#include "CShape.h"
#include <sstream>
#include <iomanip>

CShape::CShape(uint32_t outlineColor)
	: m_outlineColor(outlineColor)
{
}

uint32_t CShape::GetOutlineColor() const 
{	
	return m_outlineColor; 
}

std::string CShape::IntToHexString(uint32_t number)
{
	std::stringstream stream;
	stream << std::setfill('0') << std::setw(6) << std::hex << number;
	return stream.str();
}