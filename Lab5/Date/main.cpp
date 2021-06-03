#include "CDate.h"
#include <iostream>
#include <iomanip>

int main()
{
	CDate date(7, FEBRUARY, 1973);
	std::cout << date;

	return 0;
}