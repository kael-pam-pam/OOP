#pragma once
#include "CShape.h"
#include "CSolidShape.h"
#include "CPoint.h"
#include <string>

class CRectangle : public CShape, public CSolidShape
{
public:
	CRectangle(const CPoint& leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor);
	CRectangle(const CPoint& leftTop, const CPoint& rightBottom, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	double m_width;
	double m_height;
};