#pragma once
#include "IShape.h"
#include <string>

class CShape : virtual public IShape
{
public:
	CShape(uint32_t outlineColor);
	uint32_t GetOutlineColor() const override;
	static std::string IntToHexString(uint32_t number);
private:
	uint32_t m_outlineColor;
};