#pragma once
#include "CUrlParsingError.h"
#include "CHttpUrl.h"
#include <iostream>

class CDashboard
{
public:
	CDashboard(std::istream& input, std::ostream& output);
	bool HandleCommand();
	void PrintURLInfo(const CHttpUrl& url);

private:
	std::istream& m_input;
	std::ostream& m_output;
};
