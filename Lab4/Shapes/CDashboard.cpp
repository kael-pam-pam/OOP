#include "CDashboard.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <sstream>
#include <iterator>
#include <algorithm>

CDashboard::CDashboard(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "line", [this](std::istream& args) {
			SetTempInputArgs(args);
			AddLine();
			return true;
		}},
		{ "triangle", [this](std::istream& args) {
			SetTempInputArgs(args);
			AddTriangle();
			return true;
		}},
		{ "rectangle", [this](std::istream& args) {
			SetTempInputArgs(args);
			AddRectangle();
			return true;
		}},
		{ "circle", [this](std::istream& args) {
			SetTempInputArgs(args);
			AddCircle();
			return true;
		}},
		{ "printShapes", [this](std::istream& args) {
			SetTempInputArgs(args);
			PrintShapes();
			return true;
		}},
		})
{
}

bool CDashboard::HandleCommand()
{
	std::string commandLine;
	getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CDashboard::SetTempInputArgs(std::istream& strm)
{
	m_tempInputArgs.clear();

	std::istream_iterator<std::string> strmBegin(strm);
	std::istream_iterator<std::string> strmEnd;
	std::copy(strmBegin, strmEnd, std::inserter(m_tempInputArgs, m_tempInputArgs.begin()));
	return true;
}

bool CDashboard::AddLine()
{	
	double startPointX, startPointY, endPointX, endPointY;
	uint32_t outlineColor;
	try
	{
		if (m_tempInputArgs.size() != 5)
		{
			throw std::out_of_range("Invalid hex color");
		}
		startPointX = stod(m_tempInputArgs[0]);
		startPointY = stod(m_tempInputArgs[1]);
		endPointX = stod(m_tempInputArgs[2]);
		endPointY = stod(m_tempInputArgs[3]);
		outlineColor = stoul(m_tempInputArgs[4], nullptr, 16);
	}
	catch (std::exception&)
	{
		m_output << "Uncorrect arguments\n";
		return false;
	}
	
	m_shapeList.push_back(std::make_shared<CLineSegment>(CPoint(startPointX, startPointY), CPoint(endPointX, endPointY), outlineColor));
	return true;
}

bool CDashboard::AddTriangle()
{
	double vertex1X, vertex1Y, vertex2X, vertex2Y, vertex3X, vertex3Y;
	uint32_t outlineColor, fillColor;
	try
	{
		if (m_tempInputArgs.size() != 8)
		{
			throw std::out_of_range("Invalid hex color");
		}
		vertex1X = stod(m_tempInputArgs[0]);
		vertex1Y = stod(m_tempInputArgs[1]);
		vertex2X = stod(m_tempInputArgs[2]);
		vertex2Y = stod(m_tempInputArgs[3]);
		vertex3X = stod(m_tempInputArgs[4]);
		vertex3Y = stod(m_tempInputArgs[5]);
		outlineColor = stoul(m_tempInputArgs[6], nullptr, 16);
		fillColor = stoul(m_tempInputArgs[7], nullptr, 16);
	}
	catch (std::exception&)
	{
		m_output << "Uncorrect arguments\n";
		return false;
	}

	m_shapeList.push_back(std::make_shared<CTriangle>(CPoint(vertex1X, vertex1Y), CPoint(vertex2X, vertex2Y), CPoint(vertex3X, vertex3Y), outlineColor, fillColor));
	return true;
}

bool CDashboard::AddRectangle()
{
	double leftTopX, leftTopY, width, height;
	uint32_t outlineColor, fillColor;
	try
	{
		if (m_tempInputArgs.size() != 6)
		{
			throw std::out_of_range("Invalid hex color");
		}
		leftTopX = stod(m_tempInputArgs[0]);
		leftTopY = stod(m_tempInputArgs[1]);
		width = stod(m_tempInputArgs[2]);
		height = stod(m_tempInputArgs[3]);
		outlineColor = stoul(m_tempInputArgs[4], nullptr, 16);
		fillColor = stoul(m_tempInputArgs[5], nullptr, 16);
	}
	catch (std::exception&)
	{
		m_output << "Uncorrect arguments\n";
		return false;
	}

	m_shapeList.push_back(std::make_shared<CRectangle>(CPoint(leftTopX, leftTopY), width, height, outlineColor, fillColor));
	return true;
}

bool CDashboard::AddCircle()
{
	double centerX, centerY, radius;
	uint32_t outlineColor, fillColor;
	try
	{
		if (m_tempInputArgs.size() != 5)
		{
			throw std::out_of_range("Invalid hex color");
		}
		centerX = stod(m_tempInputArgs[0]);
		centerY = stod(m_tempInputArgs[1]);
		radius = stod(m_tempInputArgs[2]);
		outlineColor = stoul(m_tempInputArgs[3], nullptr, 16);
		fillColor = stoul(m_tempInputArgs[4], nullptr, 16);
	}
	catch (std::exception&)
	{
		m_output << "Uncorrect arguments\n";
		return false;
	}

	m_shapeList.push_back(std::make_shared<CCircle>(CPoint(centerX, centerY), radius, outlineColor, fillColor));
	return true;
}

bool CDashboard::PrintShapeWithMaxArea() const
{
	if (m_shapeList.size() == 0)
	{
		m_output << "Empty shape list\n";
		return false;
	}

	auto it = std::max_element(m_shapeList.cbegin(), m_shapeList.cend(), [](const auto& shape1, const auto& shape2) {
		return shape1->GetArea() < shape2->GetArea();
	});

	m_output << "Shape with max area is " << (*it)->ToString() << "\n";
	return true;
}

bool CDashboard::PrintShapeWithMinPerimeter() const
{
	if (m_shapeList.size() == 0)
	{
		m_output << "Empty shape list\n";
		return false;
	}

	auto it = std::min_element(m_shapeList.cbegin(), m_shapeList.cend(), [](const auto& shape1, const auto& shape2) {
		return shape1->GetPerimeter() < shape2->GetPerimeter();
		});

	m_output << "Shape with min perimeter is " << (*it)->ToString() << "\n";
	return true;
}

bool CDashboard::PrintShapes() const
{
	if (m_shapeList.size() == 0)
	{
		m_output << "Empty shape list\n";
		return false;
	}

	for (auto shape : m_shapeList)
	{
		m_output << shape->ToString() << "\n";
	}
	return true;
}