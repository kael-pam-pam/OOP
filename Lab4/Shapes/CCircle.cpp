#include "CCircle.h"
#include <cmath>

CCircle::CCircle(const CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor)
	: m_center(center)
	, m_radius(radius)
	, CSolidShape(outlineColor, fillColor)
{
}

double CCircle::GetArea() const
{ 
	return atan(1) * 4 * pow(m_radius, 2); 
}
	
double CCircle::GetPerimeter() const
{ 
	return 2 * atan(1) * 4 * m_radius; 
}

std::string CCircle::ToString() const
{
	return "Circle:\n  Center: " + m_center.ToString() + "\n  Radius: " + std::to_string(m_radius) +
		"\n  Area: " + std::to_string(GetArea()) + "\n  Perimeter: " + std::to_string(GetPerimeter()) +
		"\n  Ouline color: " + CShape::IntToHexString(GetOutlineColor()) + "\n  Fill color: " + CShape::IntToHexString(GetFillColor());
}

CPoint CCircle::GetCenter() const 
{ 
	return m_center; 
}

double CCircle::GetRadius() const 
{ 
	return m_radius; 
}
