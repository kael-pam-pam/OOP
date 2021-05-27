#pragma once
#include "IShape.h"
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

class CDashboard
{
public:
	CDashboard(std::istream& input, std::ostream& output);
	bool HandleCommand();

	bool PrintShapeWithMaxArea() const;
	bool PrintShapeWithMinPerimeter() const;
	bool PrintShapes() const;
	static bool IsHexColor(const std::string& inputStr);
private:
	bool SetTempInputArgs(std::istream& strm);

	bool AddLine();
	bool AddTriangle();
	bool AddRectangle();
	bool AddCircle();

	std::istream& m_input;
	std::ostream& m_output;
	
	std::vector<std::string> m_tempInputArgs;
	const std::map<std::string, std::function<bool(std::istream& args)>> m_actionMap;
	std::vector<std::shared_ptr<IShape>> m_shapeList;
};


/*

#include <sstream>
#include <iomanip>


static std::string IntToHexString(uint32_t number);

std::string IntToHexString(uint32_t number)
{
	std::stringstream stream;
	stream << std::setfill('0') << std::setw(6) << std::hex << 125;
	std::cout << stream.str();
}

*/

