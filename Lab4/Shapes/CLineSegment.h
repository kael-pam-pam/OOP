#pragma once
#include "CShape.h"
#include "CPoint.h"
#include <string>

class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};