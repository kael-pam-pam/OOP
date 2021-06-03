#include "CTriangle.h"
#include "lib.h"
#include <cmath>

CTriangle::CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, CSolidShape(outlineColor, fillColor)
{
}

double CTriangle::GetArea() const
{
	double halfPerimeter = GetPerimeter() / 2;
	return sqrt(halfPerimeter * (halfPerimeter - GetSide1()) * (halfPerimeter - GetSide2()) * (halfPerimeter - GetSide3()));
}

double CTriangle::GetPerimeter() const
{
	return GetSide1() + GetSide2() + GetSide3();
}

std::string CTriangle::ToString() const
{
	return "Triangle:\n  First vertex: " + m_vertex1.ToString() + "\n  Second vertex: " + m_vertex2.ToString() + "\n  Third vertex: " + m_vertex3.ToString() +
		"\n  First side: " + std::to_string(GetSide1()) + "\n  Second side: " + std::to_string(GetSide2()) + "\n  Third side: " + std::to_string(GetSide3()) +
		"\n  Area: " + std::to_string(GetArea()) + "\n  Perimeter: " + std::to_string(GetPerimeter()) +
		"\n  Ouline color: " + CShape::IntToHexString(GetOutlineColor()) + "\n  Fill color: " + CShape::IntToHexString(GetFillColor());
}
	
CPoint CTriangle::GetVertex1() const 
{ 
	return m_vertex1; 
}

CPoint CTriangle::GetVertex2() const 
{ 
	return m_vertex2; 
}

CPoint CTriangle::GetVertex3() const 
{ 
	return m_vertex3; 
}

double CTriangle::GetSide1() const 
{ 
	return GetDistance(m_vertex1, m_vertex2);
}

double CTriangle::GetSide2() const 
{ 
	return GetDistance(m_vertex2, m_vertex3);
}

double CTriangle::GetSide3() const 
{ 
	return GetDistance(m_vertex3, m_vertex1);
}

