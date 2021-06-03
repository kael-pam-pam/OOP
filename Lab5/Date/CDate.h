#pragma once
#include "lib.h"
#include <iostream>


class CDate
{
public:
	CDate(int day, Month month, int year);
	explicit CDate(int timestamp = 0);
	int GetDay() const;
	Month GetMonth() const;
	int GetYear() const;
	int GetDayOfYear() const;
	WeekDay GetWeekDay() const;
	bool IsValid() const;

	bool operator==(const CDate& rDate) const;
	bool operator!=(const CDate& rDate) const;
	CDate& operator+=(int days);
	CDate& operator-=(int days);
	bool operator>(const CDate& rDate) const;
	bool operator<(const CDate& rDate) const;
	bool operator>=(const CDate& rDate) const;
	bool operator<=(const CDate& rDate) const;
	int operator-(const CDate& rDate) const;
	const CDate operator-(int days) const;
	const CDate operator+(int days) const;
	CDate& operator++();
	const CDate& operator++(int);
	CDate& operator--();
	const CDate& operator--(int);
	friend std::ostream& operator<<(std::ostream& sOut, const CDate& rDate);
private:
	void SetIsValid();
	int m_days = 0;
	bool m_isValid = true;
};

