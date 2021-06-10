#include "CDate.h"
#include <iomanip>

CDate::CDate(int day, Month month, int year)
{			
	if (year >= 1970 && year <= 9999 && static_cast<int>(month) >= 1 && static_cast<int>(month) <= 12 && day >= 1 && day <= DaysInMonth(year, static_cast<int>(month) - 1))
	{
		int cYear = 1970, cMonth = 0, cDays = 0;
		while (cYear < year)
		{
			cDays += DaysInYear(cYear);
			cYear++;
		}

		while (cMonth < static_cast<int>(month) - 1)
		{
			cDays += DaysInMonth(cYear, cMonth);
			cMonth++;
		}
		cDays += day - 1;
		m_days = cDays;
		return;
	}
	m_days = 0;
	m_isValid = false;
}

CDate::CDate(int timestamp)
	: m_days(timestamp)
{
	SetIsValid();
	if (!m_isValid)
	{
		m_days = 0;
	}
}

int CDate::GetDay() const
{
	int days;
	Month month;
	GetMonthAndDayOfMonth(m_days, month, days);
	return days;
}

Month CDate::GetMonth() const
{
	int days;
	Month month;
	GetMonthAndDayOfMonth(m_days, month, days);
	return month;
}

int CDate::GetYear() const
{
	int year, days;
	GetYearAndDayOfYear(m_days, year, days);
	return year;
}

int CDate::GetDayOfYear() const
{
	int year, days;
	GetYearAndDayOfYear(m_days, year, days);
	return days;
}

WeekDay CDate::GetWeekDay() const
{
	//01.01.1970 это THURSDAY
	switch (m_days % 7)
	{
	case 0: return WeekDay::THURSDAY;
	case 1: return WeekDay::FRIDAY;
	case 2: return WeekDay::SATURDAY;
	case 3: return WeekDay::SUNDAY;
	case 4: return WeekDay::MONDAY;
	case 5: return WeekDay::TUESDAY;
	default: return WeekDay::WEDNESDAY;
	}
}

void CDate::SetIsValid()
{
	if (!m_isValid)
	{
		return;
	}
	//2932896 - количество дней, прибавив которое к крайнему значению "01.01.1970" получим крайнее значение "31.12.9999"
	m_isValid = (m_days >= 0) && (m_days <= 2932896);
}

bool CDate::IsValid() const
{
	return m_isValid;
}

bool CDate::operator==(const CDate& rDate) const
{
	return m_days == rDate.m_days;
}

bool CDate::operator!=(const CDate& rDate) const
{
	return m_days != rDate.m_days;
}

CDate& CDate::operator+=(int days)
{
	if (m_isValid)
	{
		m_days += days;
		SetIsValid();
	}
	return *this;
}

CDate& CDate::operator-=(int days)
{
	if (m_isValid)
	{
		m_days -= days;
		SetIsValid();
	}
	return *this;
}

bool CDate::operator>(const CDate& rDate) const
{
	return m_days > rDate.m_days;
}

bool CDate::operator<(const CDate& rDate) const
{
	return m_days < rDate.m_days;
}

bool CDate::operator>=(const CDate& rDate) const
{
	return m_days >= rDate.m_days;
}

bool CDate::operator<=(const CDate& rDate) const
{
	return m_days <= rDate.m_days;
}

int CDate::operator-(const CDate& rDate) const
{
	return m_days - rDate.m_days;
}

const CDate CDate::operator-(int days) const
{
	return CDate(m_days - days);
}

const CDate CDate::operator+(int days) const
{
	return CDate(m_days + days);
}

CDate& CDate::operator++()
{
	if (m_isValid)
	{
		++m_days;
		SetIsValid();
	}
	return *this;
}

const CDate& CDate::operator++(int)
{
	CDate tmpCopy(*this);
	if (m_isValid)
	{
		++m_days;
		SetIsValid();
	}
	return tmpCopy;
}

CDate& CDate::operator--()
{
	if (m_isValid)
	{
		--m_days;
		SetIsValid();
	}
	return *this;
}

const CDate& CDate::operator--(int)
{
	CDate tmpCopy(*this);
	if (m_isValid)
	{
		--m_days;
		SetIsValid();
	}
	return tmpCopy;
}

std::ostream& operator<<(std::ostream& sOut, const CDate& rDate)
{
	if (rDate.IsValid())
	{
		char prevFill = sOut.fill();
		std::streamsize prevWidth = sOut.width();
		sOut << std::setfill('0') << std::setw(2) << rDate.GetDay() << "." << std::setw(2) << static_cast<int>(rDate.GetMonth()) << "." << rDate.GetYear() << std::setw(prevWidth) << std::setfill(prevFill);
	}
	else
	{
		sOut << "INVALID";
	}
	return sOut;
}
