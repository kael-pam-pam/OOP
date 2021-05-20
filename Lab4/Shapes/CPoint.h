#pragma once
#include <string>

class CPoint
{
public:
	CPoint(double x, double y);
	double GetX() const;
	double GetY() const;
	std::string ToString() const;
private:
	double m_x;
	double m_y;
};
