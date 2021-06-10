#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <regex>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

CHttpUrl::CHttpUrl(const std::string& url)
{
	std::regex tmplate(R"(^(http|https)://([^:/? #]+)(:\d+)?(/[^? #]*)?(\?[^ #]*)?(#[^ ]*)?$)");
	std::cmatch arrayParse;

	if (std::regex_match(url.c_str(), arrayParse, tmplate))
	{
		m_protocol = StrToProtocol(std::string(arrayParse[1]));
		m_domain = std::string(arrayParse[2]);
		
		if (std::string(arrayParse[3]) == "")
		{		
			m_port = GetStandartPort(m_protocol);
		}
		else
		{
			m_port = StrToPort(std::string(arrayParse[3]).substr(1, std::string::npos));
		}

		m_document = std::string(arrayParse[4]);
	}
	else
	{
		throw CUrlParsingError("Invalid URL. Type like <protocol>://<domain>:<port>/<document>.\n");
	}
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol)
	: m_domain(domain)
	, m_protocol(protocol)
{
	if (domain == "")
	{
		throw std::invalid_argument("Invalid URL. Type <domain>.\n");
	}
	m_document = RepairDocumnent(document);
	m_port = GetStandartPort(m_protocol);
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
	: m_domain(domain)
	, m_protocol(protocol)
{
	if (domain == "")
	{
		throw std::invalid_argument("Invalid URL. Type <domain>.\n");
	}
	m_domain = domain;
	m_document = RepairDocumnent(document);
	m_protocol = protocol;
	m_port = ValidatePort(port);
}

std::string CHttpUrl::GetURL() const
{
	std::string url = GetProtocolStr() + "://" + m_domain;
	if (m_port != GetStandartPort(m_protocol))
	{
		url += ":" + std::to_string(m_port);
	}
	return url + m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

std::string CHttpUrl::GetProtocolStr() const
{
	return (m_protocol == Protocol::HTTP) ? "http" : "https";
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol StrToProtocol(std::string protocolStr)
{
	transform(protocolStr.begin(), protocolStr.end(), protocolStr.begin(), tolower);
	if (protocolStr == "http")
	{
		return Protocol::HTTP;
	}
	if (protocolStr == "https")
	{
		return Protocol::HTTPS;
	}
	throw std::invalid_argument("Uncnown protocol. Type <http> or <https>.\n");
}

unsigned short StrToPort(const std::string& portStr)
{
	int port = std::stoi(portStr);
	return ValidatePort(port);
}

unsigned short ValidatePort(int port)
{
	if (port < 1 || port > MAX_PORT_NUMBER)
	{
		throw std::out_of_range("Port number is too small/big");
	}
	return port;
}

unsigned short GetStandartPort(Protocol protocol)
{
	if (protocol == Protocol::HTTP)
	{
		return HTTP_PORT_NUMBER;
	}
	if (protocol == Protocol::HTTPS)
	{
		return HTTPS_PORT_NUMBER;
	}
	throw std::invalid_argument("Uncnown protocol and his standart port. Use <http> or <https>.\n");
}

std::string RepairDocumnent(const std::string& document)
{
	if (document == "")
	{
		return "/";
	}
	return ((document[0] != '/') ? "/" : "") + document;
}