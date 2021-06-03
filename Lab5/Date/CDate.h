#pragma once
#include "lib.h"
#include <iostream>


class CDate
{
public:
	CDate(unsigned day, Month month, unsigned year);
	explicit CDate(unsigned timestamp = 0);
	unsigned GetDay() const;
	Month GetMonth() const;
	unsigned GetYear() const;
	unsigned GetDayOfYear() const;
	WeekDay GetWeekDay() const;
	bool IsValid() const;

	bool operator==(const CDate& rDate) const;
	bool operator!=(const CDate& rDate) const;
	CDate& operator+=(unsigned days);
	CDate& operator-=(unsigned days);
	bool operator>(const CDate& rDate) const;
	bool operator<(const CDate& rDate) const;
	bool operator>=(const CDate& rDate) const;
	bool operator<=(const CDate& rDate) const;
	int32_t operator-(const CDate& rDate) const;
	const CDate operator-(unsigned days) const;
	const CDate operator+(unsigned days) const;
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

