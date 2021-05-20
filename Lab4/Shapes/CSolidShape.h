#pragma once
#include "ISolidShape.h"

class CSolidShape : virtual public ISolidShape
{
public:
	CSolidShape(uint32_t fillColor);
	uint32_t GetFillColor() const override;
private:
	uint32_t m_fillColor;
};