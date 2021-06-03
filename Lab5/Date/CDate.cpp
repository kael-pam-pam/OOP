#include "CDate.h"
#include <iomanip>

CDate::CDate(unsigned day, Month month, unsigned year)
{			
	if (year >= 1970 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= DaysInMonth(year, month - 1))
	{
		unsigned cYear = 1970, cMonth = 0, cDays = 0;
		while (cYear < year)
		{
			cDays += DaysInYear(cYear);
			cYear++;
		}

		while (cMonth < month - 1)
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

CDate::CDate(unsigned timestamp)
	: m_days(timestamp)
{
}

unsigned CDate::GetDay() const
{
	unsigned days;
	Month month;
	GetMonthAndDayOfMonth(m_days, month, days);
	return days;
}

Month CDate::GetMonth() const
{
	unsigned days;
	Month month;
	GetMonthAndDayOfMonth(m_days, month, days);
	return month;
}

unsigned CDate::GetYear() const
{
	unsigned year, days;
	GetYearAndDayOfYear(m_days, year, days);
	return year;
}

unsigned CDate::GetDayOfYear() const
{
	unsigned year, days;
	GetYearAndDayOfYear(m_days, year, days);
	return days;
}

WeekDay CDate::GetWeekDay() const
{
	switch (m_days % 7)
	{
		case 0: return THURSDAY;
		case 1: return FRIDAY;
		case 2: return SATURDAY;
		case 3: return SUNDAY;
		case 4: return MONDAY;
		case 5: return TUESDAY;
		case 6: return WEDNESDAY;
		default:;
	}
}

void CDate::setIsValid()
{
	if (!m_isValid)
	{
		return;
	}
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

CDate& CDate::operator+=(unsigned days)
{
	if (IsValid())
	{
		m_days += days;
	}
	return *this;
}

CDate& CDate::operator-=(unsigned days)
{
	if (IsValid())
	{
		m_days -= days;
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

int32_t CDate::operator-(const CDate& rDate) const
{
	return m_days - rDate.m_days;
}

const CDate CDate::operator-(unsigned days) const
{
	return CDate(m_days - days);
}

const CDate CDate::operator+(unsigned days) const
{
	return CDate(m_days + days);
}

CDate& CDate::operator++()
{
	if (IsValid())
	{
		++m_days;
	}
	return *this;
}

const CDate& CDate::operator++(int)
{
	CDate tmpCopy(*this);
	if (IsValid())
	{
		++m_days;
	}
	return tmpCopy;
}

CDate& CDate::operator--()
{
	if (IsValid())
	{
		--m_days;
	}
	return *this;
}

const CDate& CDate::operator--(int)
{
	CDate tmpCopy(*this);
	if (IsValid())
	{
		--m_days;
	}
	return tmpCopy;
}

std::ostream& operator<<(std::ostream& sOut, const CDate& rDate)
{
	if (rDate.IsValid())
	{
		sOut << std::setfill('0') << std::setw(2) << rDate.GetDay() << "." << std::setw(2) << static_cast<int>(rDate.GetMonth()) << "." << rDate.GetYear();
	}
	else
	{
		sOut << "INVALID";
	}
	return sOut;
}
