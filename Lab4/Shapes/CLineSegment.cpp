#include "CLineSegment.h"
#include <cmath>

CLineSegment::CLineSegment(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, CShape(outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return hypot(m_startPoint.GetX() - m_endPoint.GetX(), m_startPoint.GetY() - m_endPoint.GetY());
}

std::string CLineSegment::ToString() const
{
	return "Line:\n  Start point: " + m_startPoint.ToString() + "\n  End point: " + m_endPoint.ToString() + "\n  Area: " + std::to_string(GetArea())
		+ "\n  Perimeter: " + std::to_string(GetPerimeter()) + "\n  Ouline color: " + std::to_string(GetOutlineColor());
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}
