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
#include "../Shapes/lib.h"

#include <string>
using namespace Catch::literals;

TEST_CASE("Test class CLineSegment")
{
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
	std::string outputString = "Rectangle:\n  Height: 5.000000\n  Width: 10.000000\n  Left top point: (1.000000, 1.000000)\n  Area: 50.000000\n  Perimeter: 30.000000\n  Ouline color: 000005\n  Fill color: 12345f";
							   
	CRectangle rectangle(CPoint(1, 1), 10, 5, 5, 1193055);

	REQUIRE(rectangle.GetArea() == 50.0);
	REQUIRE(rectangle.GetPerimeter() == 30.0);
	REQUIRE(rectangle.ToString() == outputString);
	REQUIRE(rectangle.GetWidth() == 10.0);
	REQUIRE(rectangle.GetHeight() == 5.0);
}

TEST_CASE("Test class CCircle")
{
	std::string outputString = "Circle:\n  Center: (1.000000, 1.000000)\n  Radius: 5.500000\n  Area: 95.033178\n  Perimeter: 34.557519\n  Ouline color: 12345f\n  Fill color: 000005";

	CCircle circle(CPoint(1, 1), 5.5, 1193055, 5);

	REQUIRE(Approx(circle.GetArea()).epsilon(1e-8) == 95.033178);
	REQUIRE(Approx(circle.GetPerimeter()).epsilon(1e-8) == 34.557519);
	REQUIRE(circle.ToString() == outputString);
	REQUIRE(circle.GetCenter().GetX() == 1);
	REQUIRE(circle.GetCenter().GetY() == 1);
	REQUIRE(circle.GetRadius() == 5.5);
}

TEST_CASE("Test class CTriangle")
{
	std::string outputString = "Triangle:\n  First vertex: (1.000000, 1.000000)\n  Second vertex: (5.000000, 1.000000)\n  Third vertex: (3.000000, 5.000000)\n  First side: 4.000000\n  Second side: 4.472136\n  Third side: 4.472136\n  Area: 8.000000\n  Perimeter: 12.944272\n  Ouline color: 12345f\n  Fill color: 000005";
	
	CTriangle triangle(CPoint(1, 1), CPoint(5, 1), CPoint(3, 5), 1193055, 5);

	REQUIRE(Approx(triangle.GetArea()).epsilon(1e-8) == 8.0);
	REQUIRE(Approx(triangle.GetPerimeter()).epsilon(1e-8) == 12.94427191);
	REQUIRE(triangle.ToString() == outputString);
	REQUIRE(triangle.GetVertex1().GetX() == 1);
	REQUIRE(triangle.GetVertex1().GetY() == 1);
	REQUIRE(triangle.GetSide1() == 4);
}


TEST_CASE("Test class CDashboard")
{
	std::istringstream input("line 1.1 1.2 5.1 1.2 f12345\ntriangle 1 1 5 1 3 5 12345f 000005\ncircle 1 1 5.5 12345f 000005\nrectangle 1 1 10 5 000005 12345f\nprintShapes\n");
	std::ostringstream output;
	CDashboard dashboard(input, output);

	dashboard.PrintShapes();
	REQUIRE("Shape list has no one element for print\n" == output.str());

	output.str("");
	dashboard.PrintShapeWithMaxArea();
	REQUIRE("Shape list has no one element with max area\n" == output.str());

	output.str("");
	dashboard.PrintShapeWithMinPerimeter();
	REQUIRE("Shape list has no one element with min perimeter\n" == output.str());
	
	output.str("");
	dashboard.HandleCommand();
	dashboard.HandleCommand();
	dashboard.HandleCommand();
	dashboard.HandleCommand();
	REQUIRE("" == output.str());
	
	output.str("");
	input.str("triangle 3\ntriangle 1 1 5 1 3 5 1L345f");
	dashboard.HandleCommand();
	REQUIRE("Uncorrect arguments\n" == output.str());

	output.str("");
	dashboard.HandleCommand();
	REQUIRE("Uncorrect arguments\n" == output.str());
}
