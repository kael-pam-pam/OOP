#pragma once
#include <string>
#include <iostream>

class CFunctionCall
{
public:
	CFunctionCall(const std::string& functionName)
		:m_functionName(functionName)
	{
		std::cout << "Entering " << functionName << "\n";
	}
	~CFunctionCall()
	{
		std::cout << "Exiting " << m_functionName << "\n";
	}
private:
	const std::string m_functionName;
};
