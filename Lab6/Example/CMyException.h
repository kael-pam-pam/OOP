#pragma once
#include <iostream>

class CMyException
{
public:
	CMyException()
		:m_copy(0)
	{
		std::cout << "CMyException is being created\n";
	}
	int GetCopyIndex() const
	{
		return m_copy;
	}
	CMyException(const CMyException& e)
		:m_copy(e.m_copy + 1)
	{
		std::cout << "CMyException copy #" << m_copy << " is being created\n";
	}
	~CMyException()
	{
		std::cout << "CMyException copy #" << m_copy << " is being destroyed\n";
	}
private:
	int m_copy;
};