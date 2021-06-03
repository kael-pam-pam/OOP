#include "CDate.h"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Hello world!\n";
	//std::cout << JANUARY << FEBRUARY << MARCH << APRIL << MAY << JUNE << JULY << AUGUST << SEPTEMBER << OCTOBER << NOVEMBER << DECEMBER << "\n";
	//std::cout << SUNDAY << MONDAY << TUESDAY << WEDNESDAY << THURSDAY << FRIDAY << SATURDAY;

	/*
	unsigned short x = -1;
	std::cout << "\n" << x << "\n";
	x = 65535 + 1;
	std::cout << x << "\n";
	*/
	//std::cout << static_cast<Month>(-99);
	CDate date(7, FEBRUARY, 1973);
	std::cout << date;

	return 0;
}