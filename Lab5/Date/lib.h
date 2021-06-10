#pragma once

enum class Month
{
	JANUARY = 1, FEBRUARY, MARCH, APRIL,
	MAY, JUNE, JULY, AUGUST, SEPTEMBER,
	OCTOBER, NOVEMBER, DECEMBER
};

enum class WeekDay
{
	SUNDAY = 0, MONDAY, TUESDAY, WEDNESDAY,
	THURSDAY, FRIDAY, SATURDAY
};

bool IsLeapYear(int year);
int DaysInYear(int year);
int DaysInMonth(int year, int month);
void GetYearAndDayOfYear(int inputDays, int& outputYear, int& outputDays);
void GetMonthAndDayOfMonth(int inputDays, Month& outputMonth, int& outputDay);