#pragma once
#include <string>
#include <iostream>

class CObject
{
public:
	CObject(const std::string& objectName)
		:m_objectName(objectName)
	{
		std::cout << m_objectName << " is being created\n";
	}

	~CObject()
	{
		std::cout << m_objectName << " is being destroyed\n";
	}
private:
	const std::string m_objectName;
};