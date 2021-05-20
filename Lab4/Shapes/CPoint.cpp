#include "CPoint.h"

CPoint::CPoint(double x, double y)
	: m_x(x)
	, m_y(y)
{
}

double CPoint::GetX() const 
{ 
	return m_x; 
}

double CPoint::GetY() const
{
	return m_y;
}

std::string CPoint::ToString() const 
{ 
	return "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")"; 
}
