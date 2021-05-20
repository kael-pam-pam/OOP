#pragma once
#include "CShape.h"
#include "CSolidShape.h"
#include "CPoint.h"
#include <string>

class CCircle : public CShape, public CSolidShape
{
public:
	CCircle(const CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetCenter() const;
	double GetRadius() const;
private:
	CPoint m_center;
	double m_radius;
};