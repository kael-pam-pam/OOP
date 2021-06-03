#pragma once

enum Month
{
	JANUARY = 1, FEBRUARY, MARCH, APRIL,
	MAY, JUNE, JULY, AUGUST, SEPTEMBER,
	OCTOBER, NOVEMBER, DECEMBER
};

enum WeekDay
{
	SUNDAY = 0, MONDAY, TUESDAY, WEDNESDAY,
	THURSDAY, FRIDAY, SATURDAY
};

bool IsLeapYear(unsigned year);
unsigned DaysInYear(unsigned year);
unsigned DaysInMonth(unsigned year, unsigned month);
void GetYearAndDayOfYear(unsigned inputDays, unsigned& outputYear, unsigned& outputDays);
void GetMonthAndDayOfMonth(unsigned inputDays, Month& outputMonth, unsigned& outputDay);