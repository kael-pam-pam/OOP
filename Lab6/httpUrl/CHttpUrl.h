#pragma once
#include <string>

enum class Protocol
{
	HTTP,
	HTTPS,
	UNCNOWN
};

const int MAX_PORT_NUMBER = 65535;
const int HTTP_PORT_NUMBER = 80;
const int HTTPS_PORT_NUMBER = 443;

class CHttpUrl
{
public:
	CHttpUrl(const std::string& url);
	CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol = Protocol::HTTP);
	CHttpUrl(const std::string& domain,	const std::string& document, Protocol protocol, unsigned short port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;	
	unsigned short GetPort() const;	
private:
	std::string GetProtocolStr() const;

	std::string m_domain;
	std::string m_document = "";
	Protocol m_protocol;
	unsigned short m_port;
};

Protocol StrToProtocol(std::string protocolStr);
unsigned short StrToPort(const std::string& portStr);
unsigned short GetStandartPort(Protocol protocol);
std::string RepairDocumnent(const std::string& document);
unsigned short ValidatePort(int port);
