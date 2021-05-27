#include "CRectangle.h"

CRectangle::CRectangle(const CPoint& leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, CSolidShape(outlineColor, fillColor)
	, m_rightBottom(leftTop.GetY() + height, leftTop.GetX() + width)
{
}

/*
CRectangle::CRectangle(const CPoint& leftTop, const CPoint& rightBottom, uint32_t outlineColor, uint32_t fillColor)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
	, CSolidShape(outlineColor, fillColor)
	, m_height(leftTop.GetY() - rightBottom.GetY())
	, m_width(rightBottom.GetX() - leftTop.GetX())
{
}
*/

double CRectangle::GetArea() const 
{ 
	return m_width * m_height; 
}

double CRectangle::GetPerimeter() const 
{ 
	return (m_width + m_height) * 2; 
}

std::string CRectangle::ToString() const
{
	return "Rectangle:\n  Height: " + std::to_string(m_height) + "\n  Width: " + std::to_string(m_width) +
		"\n  Left top point: " + m_leftTop.ToString() + "\n  Right bottom point: " + m_rightBottom.ToString() +
		"\n  Area: " + std::to_string(GetArea()) + "\n  Perimeter: " + std::to_string(GetPerimeter()) +
		"\n  Ouline color: " + CShape::IntToHexString(GetOutlineColor()) + "\n  Fill color: " + CShape::IntToHexString(GetFillColor());
}

CPoint CRectangle::GetLeftTop() const 
{ 
	return m_leftTop; 
}

CPoint CRectangle::GetRightBottom() const 
{ 
	return m_rightBottom; 
}
	
double CRectangle::GetWidth() const 
{ 
	return m_width; 
}

double CRectangle::GetHeight() const 
{ 
	return m_height; 
}