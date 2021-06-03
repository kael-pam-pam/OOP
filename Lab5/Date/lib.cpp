#include "lib.h"

bool IsLeapYear(unsigned year)
{
	if (year % 4 != 0)
	{
		return false;
	}
	if (year % 100 != 0)
	{
		return true;
	}
	if (year % 400 == 0)
	{
		return true;
	}
	return false;
}

unsigned DaysInYear(unsigned year)
{
	return (IsLeapYear(year)) ? 366 : 365;
}

unsigned DaysInMonth(unsigned year, unsigned month)
{
	unsigned daysInMonth[12] = { 31, (IsLeapYear(year)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return daysInMonth[month];
}

void GetYearAndDayOfYear(unsigned inputDays, unsigned& outputYear, unsigned& outputDays)
{
	unsigned daysInCurrentYear, cYear = 1970, cDays = inputDays;

	daysInCurrentYear = DaysInYear(cYear);
	while (cDays / daysInCurrentYear != 0)
	{
		cDays -= daysInCurrentYear;
		cYear++;
		daysInCurrentYear = DaysInYear(cYear);
	}
	outputDays = cDays % daysInCurrentYear;
	outputYear = cYear;
}

void GetMonthAndDayOfMonth(unsigned inputDays, Month& outputMonth, unsigned& outputDay)
{
	unsigned year, month = 0, day;
	GetYearAndDayOfYear(inputDays, year, outputDay);
	day = outputDay;

	while (day / DaysInMonth(year, month) != 0)
	{
		day -= DaysInMonth(year, month);
		month++;
	}
	outputMonth = static_cast<Month>(month + 1);
	outputDay = day + 1;
}
