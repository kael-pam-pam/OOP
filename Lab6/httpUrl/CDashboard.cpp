#include "CDashboard.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

CDashboard::CDashboard(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

bool CDashboard::HandleCommand()
{
	std::string line;
	getline(m_input, line);

	std::istringstream strm(line);
	std::istream_iterator<std::string> strmBegin(strm);
	std::istream_iterator<std::string> strmEnd;
	std::vector<std::string> args = {};
	std::copy(strmBegin, strmEnd, std::inserter(args, args.begin()));

	try
	{
		if (args.size() == 1)
		{
			CHttpUrl httpUrl(args[0]);
			m_output << httpUrl.GetURL() << "\n";
			return true;
		}
		if (args.size() == 3)
		{
			CHttpUrl httpUrl(args[0], args[1], StrToProtocol(args[2]));
			m_output << httpUrl.GetURL() << "\n";
			return true;
		}
		if (args.size() == 4)
		{
			CHttpUrl httpUrl(args[0], args[1], StrToProtocol(args[2]), StrToPort(args[3]));
			m_output << httpUrl.GetURL() << "\n";
			return true;
		}
		std::string message = "Invalid input arguments. Type\n  <STRING url>\nOR\n  ";
		message += "<STRING domain, STRING document, PROTOCOL protocol>\nOR\n  ";
		message += "<STRING domain, STRING document, PROTOCOL protocol, INT port>.\n";
		throw std::invalid_argument(message);
	}
	catch (const std::exception& e)
	{
		m_output << e.what();
	}
	return true;
}
