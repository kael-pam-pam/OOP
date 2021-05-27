#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../Shapes/CPoint.h"
#include "../Shapes/CShape.h"
#include "../Shapes/CSolidShape.h"
#include "../Shapes/CLineSegment.h"
#include "../Shapes/CTriangle.h"
#include "../Shapes/CRectangle.h"
#include "../Shapes/CCircle.h"
#include "../Shapes/CDashboard.h"

#include <string>

TEST_CASE("Test class CLineSegment")
{
	using namespace Catch::literals;
	std::string outputString = "Line:\n  Start point: (1.100000, 1.200000)\n  End point: (5.100000, 1.200000)\n  Area: 0.000000\n  Perimeter: 4.000000\n  Ouline color: f12345";
	double perimeter = 4.0;
	double startPointX = 1.1, startPointY = 1.2;

	CLineSegment line(CPoint(1.1, 1.2), CPoint(5.1, 1.2), 15803205);
	
	REQUIRE(line.GetArea() == 0);
	REQUIRE(line.GetPerimeter() == Approx(perimeter).epsilon(1e-12));
	REQUIRE(line.ToString() == outputString);
	REQUIRE(line.GetStartPoint().GetX() == Approx(startPointX).epsilon(1e-12));
	REQUIRE(line.GetStartPoint().GetY() == Approx(startPointY).epsilon(1e-12));
}

TEST_CASE("Test class CRectangle")
{
	std::string outputString = "Rectangle:\n  Height: 5.000000\n  Width: 10.000000\n  Left top point: (1.000000, 1.000000)\n  Right bottom point: (6.000000, 11.000000)\n  Area: 50.000000\n  Perimeter: 30.000000\n  Ouline color: 000005\n  Fill color: 12345f";
							   
	CRectangle rectangle(CPoint(1, 1), 10, 5, 5, 1193055);

	REQUIRE(rectangle.GetArea() == 50.0);
	REQUIRE(rectangle.GetPerimeter() == 30.0);
	REQUIRE(rectangle.ToString() == outputString);
}

/*
TEST_CASE("Test class CCircle")
{
}

TEST_CASE("Test class CTriangle")
{
}
*/

TEST_CASE("Test class CDashboard")
{
	std::istringstream input("line []\ntriangle []\ncircle []\nrectangle []\nprintShapes\n");
	std::ostringstream output;
	CDashboard dashboard(input, output);

	dashboard.HandleCommand();
	REQUIRE("Engine: on\n" == output.str());
	output.str("");

}
