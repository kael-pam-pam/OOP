#pragma once
#include <string>;
#include <cmath>

//TODO: CPoint.cpp
class CPoint
{
public:
	CPoint(double x, double y) 
		: m_x(x)
		, m_y(y) 
	{
	}
	double GetX() const { return m_x; }
	double GetY() const { return m_y; }
	std::string ToString() const { return "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")"; }
private:
	double m_x;
	double m_y;
};

//TODO: .h .cpp
class IShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
};

//TODO: .h .cpp
class ISolidShape : virtual public IShape
{
public:
	virtual uint32_t GetFillColor() const = 0;
};

//TODO: .h .cpp
class CShape : virtual public IShape
{
public:
	CShape(uint32_t outlineColor)
		: m_outlineColor(outlineColor)
	{
	}
	uint32_t GetOutlineColor() const override { return m_outlineColor; }
private:
	uint32_t m_outlineColor;
};

//TODO: .h .cpp
class CSolidShape : virtual public ISolidShape
{
public:
	CSolidShape(uint32_t fillColor)
		: m_fillColor(fillColor)
	{
	}
	uint32_t GetFillColor() const override { return m_fillColor; }
private:
	uint32_t m_fillColor;
};

//TODO: .h .cpp
class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint& startPoint, const CPoint& endPoint, uint32_t outlineColor)
		: m_startPoint(startPoint)
		, m_endPoint(endPoint)
		, CShape(outlineColor)
	{
	}
	double GetArea() const override
	{
		return 0;
	}
	double GetPerimeter() const override
	{
		return hypot(m_startPoint.GetX() - m_endPoint.GetX(), m_startPoint.GetY() - m_endPoint.GetY());
	}
	std::string ToString() const override
	{
		return "Line:\n  Start point: " + m_startPoint.ToString() + "\n  End point: " + m_endPoint.ToString() + "\n  Area: " + std::to_string(GetArea())
			+ "\n  Perimeter: " + std::to_string(GetPerimeter()) + "\n  Ouline color: " + std::to_string(GetOutlineColor());
	}
	CPoint GetStartPoint() const
	{
		return m_startPoint;
	}
	CPoint GetEndPoint() const
	{
		return m_endPoint;
	}
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};

//TODO: .h .cpp
class CTriangle : public CShape, public CSolidShape
{
public:
	CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, uint32_t outlineColor, uint32_t fillColor)
		: m_vertex1(vertex1)
		, m_vertex2(vertex2)
		, m_vertex3(vertex3)
		, CShape(outlineColor)
		, CSolidShape(fillColor)
	{
	}
	double GetArea() const override
	{
		double halfPerimeter = GetPerimeter() / 2;
		return sqrt(halfPerimeter * (halfPerimeter - GetSide1()) * (halfPerimeter - GetSide2()) * (halfPerimeter - GetSide3()));
	}
	double GetPerimeter() const override
	{
		return GetSide1() + GetSide2() + GetSide3();
	}
	std::string ToString() const override
	{
		return "Triangle:\n  First vertex: " + m_vertex1.ToString() + "\n  Second vertex: " + m_vertex2.ToString() + "\n  Third vertex: " + m_vertex3.ToString() +
			"\n  First side: " + std::to_string(GetSide1()) + "\n  Second side:  " + std::to_string(GetSide2()) + "\n  Third side:  " + std::to_string(GetSide3()) +
			"\n  Area: " + std::to_string(GetArea()) + "\n  Perimeter: " + std::to_string(GetPerimeter()) +
			"\n  Ouline color: " + std::to_string(GetOutlineColor()) + "\n  Fill color: " + std::to_string(GetFillColor());
	}
	CPoint GetVertex1() const { return m_vertex1; }
	CPoint GetVertex2() const { return m_vertex2; }
	CPoint GetVertex3() const { return m_vertex3; }
	double GetSide1() const { return GetLine(m_vertex1, m_vertex2); }
	double GetSide2() const { return GetLine(m_vertex2, m_vertex3); }
	double GetSide3() const { return GetLine(m_vertex3, m_vertex1); }
private:
	double GetLine(const CPoint& vertexA, const CPoint& vertexB) const { return hypot(vertexA.GetX() - vertexB.GetX(), vertexA.GetY() - vertexB.GetY()); }
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};

//TODO: .h .cpp
class CRectangle : public CShape, public CSolidShape
{
public:
	CRectangle(const CPoint& leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor)
		: m_leftTop(leftTop)
		, m_width(width)
		, m_height(height)
		, CShape(outlineColor)
		, CSolidShape(fillColor)
		, m_rightBottom(leftTop.GetY() - height, leftTop.GetX() + width)
	{
	}
	CRectangle(const CPoint& leftTop, const CPoint& rightBottom, uint32_t outlineColor, uint32_t fillColor)
		: m_leftTop(leftTop)
		, m_rightBottom(rightBottom)
		, CShape(outlineColor)
		, CSolidShape(fillColor)
		, m_height(leftTop.GetY() - rightBottom.GetY())
		, m_width(rightBottom.GetX() - leftTop.GetX())
	{
	}
	double GetArea() const override { return m_width * m_height; }
	double GetPerimeter() const override { return (m_width + m_height) * 2; }
	std::string ToString() const override
	{ 
		return "CRectangle:\n  Height: " + std::to_string(m_height) + "\n  Width: " + std::to_string(m_width) +
			"\n  Left top point: " + m_leftTop.ToString() + "\n  Right bottom point: " + m_rightBottom.ToString() +
			"\n  Area: " + std::to_string(GetArea()) + "\n  Perimeter: " + std::to_string(GetPerimeter()) +
			"\n  Ouline color: " + std::to_string(GetOutlineColor()) + "\n  Fill color: " + std::to_string(GetFillColor());
	}
	CPoint GetLeftTop() const { return m_leftTop; }
	CPoint GetRightBottom() const { return	m_rightBottom; }
	double GetWidth() const { return m_width; }
	double GetHeight() const { return m_height; }
private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	double m_width;
	double m_height;
};

//TODO: .h .cpp
class CCircle : public CShape, public CSolidShape
{
public:
	CCircle(const CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor)
		: m_center(center)
		, m_radius(radius)
		, CShape(outlineColor)
		, CSolidShape(fillColor)
	{
	}
	double GetArea() const override { return atan(1) * 4 * pow(m_radius, 2); }
	double GetPerimeter() const override { return 2 * atan(1) * 4 * m_radius; }
	std::string ToString() const override
	{
		return "Circle:\n  Center: " + m_center.ToString() + "\n  Radius: " + std::to_string(m_radius) +
			"\n  Area: " + std::to_string(GetArea()) + "\n  Perimeter: " + std::to_string(GetPerimeter()) +
			"\n  Ouline color: " + std::to_string(GetOutlineColor()) + "\n  Fill color: " + std::to_string(GetFillColor());
	}
	CPoint GetCenter() const { return m_center; }
	double GetRadius() const { return m_radius; }
private:
	CPoint m_center;
	double m_radius;

};
