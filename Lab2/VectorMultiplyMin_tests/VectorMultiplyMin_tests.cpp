#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "../VectorMultiplyMin/VectorOfFloat.h"


TEST_CASE("Test function MultiplyVectorOfFloatByElement")
{
	using namespace Catch::literals;
	std::vector<float> a = {};
	std::vector<float> b = { 9.1f, 2.0f, 7.33f, 4.01f };

	REQUIRE(MultiplyVectorOfFloatByElement(a, 0) == (std::vector<float>{}));
	REQUIRE(MultiplyVectorOfFloatByElement(a, 3) == (std::vector<float>{}));
	REQUIRE(MultiplyVectorOfFloatByElement(b, 2) == (std::vector<float>{18.2f, 4.0f, 14.66f, 8.02f}));
	REQUIRE(MultiplyVectorOfFloatByElement(b, 0) == (std::vector<float>{0.0, 0.0, 0.0, 0.0}));
	CHECK_THAT(MultiplyVectorOfFloatByElement(b, 3.21f), Catch::Approx(std::vector<float>{29.211f, 6.42f, 23.5293f, 12.8721f}));
}

TEST_CASE("Test function GetMinElementInVectorOfFloat")
{
	std::vector<float> a = {};
	std::vector<float> b = { 9.1f, 2.0f, 7.33f, 4.01f };

	REQUIRE(GetMinElementInVectorOfFloat(a) == std::nullopt);
	REQUIRE(GetMinElementInVectorOfFloat(b) == 2.0);
}

TEST_CASE("Test function SortVectorOfFloat")
{
	std::vector<float> a = {};
	std::vector<float> b = { 9.1f, 2.0f, 7.33f, 4.01f };

	REQUIRE(SortVectorOfFloat(a) == (std::vector<float>{}));
	REQUIRE(SortVectorOfFloat(b) == (std::vector<float>{2.0f, 4.01f, 7.33f, 9.1f}));
}
