#pragma once
#include <stdexcept>
#include <iostream>

double MySqrt(double arg)
{
	if (arg < 0)
	{
		throw std::invalid_argument("Argument must not be negative");
	}
	return sqrt(arg);
}

class CSomeClass
{
public:
	CSomeClass(double arg)
	try
	:m_value(MySqrt(arg))
	{
	}
	catch (...)
	{
		std::cout << "Unable to construct CSomeClass instance\n";
		throw;
	}
private:
	double m_value;
};
