#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../Date/CDate.h"
#include "../Date/lib.h"

TEST_CASE("Test lib")
{
	REQUIRE(IsLeapYear(1970) == false);
	REQUIRE(IsLeapYear(1972) == true);
	REQUIRE(IsLeapYear(1800) == false);
	REQUIRE(IsLeapYear(2100) == false);
	REQUIRE(IsLeapYear(2104) == true);
	REQUIRE(IsLeapYear(2000) == true);
	REQUIRE(IsLeapYear(2001) == false);
}

TEST_CASE("Test class CDate")
{

	SECTION("17 FEBRUARY 1973")
	{
		CDate date(17, FEBRUARY, 1973);
		REQUIRE(date.GetYear() == 1973);
		REQUIRE(date.GetMonth() == FEBRUARY);
		REQUIRE(date.GetDay() == 17);
	}
	SECTION("3 JUNE 2021")
	{
		CDate date(3, JUNE, 2021);
		REQUIRE(date.GetYear() == 2021);
		REQUIRE(date.GetMonth() == JUNE);
		REQUIRE(date.GetDay() == 3);
	}
	SECTION("0")
	{
		CDate date(0);
		REQUIRE(date.GetDay() == 1);
		REQUIRE(date.GetMonth() == JANUARY);
		REQUIRE(date.GetYear() == 1970);
		REQUIRE(date.GetWeekDay() == THURSDAY);
		REQUIRE(date.GetDayOfYear() == 0);
	}
	SECTION("1")
	{
		CDate date(1);
		REQUIRE(date.GetDay() == 2);
		REQUIRE(date.GetMonth() == JANUARY);
		REQUIRE(date.GetYear() == 1970);
		REQUIRE(date.GetWeekDay() == FRIDAY);
		REQUIRE(date.GetDayOfYear() == 1);
	}
	SECTION("365")
	{
		CDate date(365);
		REQUIRE(date.GetDay() == 1);
		REQUIRE(date.GetMonth() == JANUARY);
		REQUIRE(date.GetYear() == 1971);
		REQUIRE(date.GetWeekDay() == FRIDAY);
		REQUIRE(date.GetDayOfYear() == 0);
	}
	SECTION("730")
	{
		CDate date(730);
		REQUIRE(date.GetDay() == 1);
		REQUIRE(date.GetMonth() == JANUARY);
		REQUIRE(date.GetYear() == 1972);
		REQUIRE(date.GetWeekDay() == SATURDAY);
		REQUIRE(date.GetDayOfYear() == 0);
	}
	SECTION("1095")
	{
		CDate date(1095);
		REQUIRE(date.GetDay() == 31);
		REQUIRE(date.GetMonth() == DECEMBER);
		REQUIRE(date.GetYear() == 1972);
		REQUIRE(date.GetWeekDay() == SUNDAY);
		REQUIRE(date.GetDayOfYear() == 365);
	}
	SECTION("OPERATOR == AND !=")
	{
		CDate date1(10), date2(10), date3(11);
		REQUIRE(date1 == date2);
		REQUIRE_FALSE(date1 == date3);
		REQUIRE_FALSE(date3 == date1);
		REQUIRE_FALSE(date1 != date2);
		REQUIRE(date1 != date3);
		REQUIRE(date3 != date1);
	}
	SECTION("OPERATOR += AND -=")
	{
		CDate date1(10), date2(10), date3(11);
		date1 += 1;
		REQUIRE(date1 == date3);
		date1 -= 1;
		REQUIRE(date1 == date2);
	}
	SECTION("OPERATOR > AND <")
	{
		CDate date1(10), date2(15), date3(5);
		REQUIRE_FALSE(date1 > date2);
		REQUIRE(date1 > date3);
		REQUIRE_FALSE(date2 < date1);
		REQUIRE(date3 < date2);
	}
	SECTION("OPERATOR >= AND <=")
	{
		CDate date1(10), date2(15), date3(5);
		REQUIRE_FALSE(date1 >= date2);
		REQUIRE(date1 >= date3);
		REQUIRE(date1 >= date1);
		REQUIRE_FALSE(date2 <= date1);
		REQUIRE(date3 <= date2);
		REQUIRE(date3 <= date3);
	}
	SECTION("OPERATOR - AND +")
	{
		CDate date1(10), date2(15), date3(5);
		REQUIRE((date2 - 5) == date1);
		REQUIRE((date2 - date3) == 10);
		REQUIRE((date3 - date2) == -10);
		REQUIRE((date3 + 5) == date1);
	}
	SECTION("OPERATOR ++")
	{
		CDate date1(10), date2(11), date3(12), date4(10);
		date1++;
		REQUIRE(date1 == date2);
		++date1;
		REQUIRE(date1 == date3);
		--date1;
		REQUIRE(date1 == date2);
		date1--;
		REQUIRE(date1 == date4);
	}
}
