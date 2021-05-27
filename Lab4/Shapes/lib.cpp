#include "lib.h"
#include <cmath>

bool IsHexColor(const std::string& inputStr)
{
	if (inputStr.length() != 6)
	{
		return false;
	}
	for (auto ch : inputStr)
	{
		if (!isdigit(ch) && !(ch >= 'a' && ch <= 'f'))
		{
			return false;
		}
	}
	return true;
}

double GetDistance(const CPoint& vertexA, const CPoint& vertexB)
{
	return hypot(vertexA.GetX() - vertexB.GetX(), vertexA.GetY() - vertexB.GetY());
}

