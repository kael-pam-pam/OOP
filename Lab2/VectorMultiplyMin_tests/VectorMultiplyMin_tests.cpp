#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../VectorMultiplyMin/VectorOfFloat.h"


TEST_CASE("Test function MultiplyVectorOfFloatByElement")
{
	using namespace Catch::literals;
	std::vector<float> a{}, a1{};
	std::vector<float> b{ 9.1f, 2.0f, 7.33f, 4.01f }, b1{ 9.1f, 2.0f, 7.33f, 4.01f }, b2{ 9.1f, 2.0f, 7.33f, 4.01f };
	
	MultiplyVectorOfFloatByElement(a, 0);
	REQUIRE(a == (std::vector<float>{}));
	MultiplyVectorOfFloatByElement(a1, 3);
	REQUIRE(a1 == (std::vector<float>{}));
	MultiplyVectorOfFloatByElement(b, 2);
	REQUIRE(b == (std::vector<float>{ 18.2f, 4.0f, 14.66f, 8.02f }));
	MultiplyVectorOfFloatByElement(b1, 0);
	REQUIRE(b1 == (std::vector<float>{ 0.0, 0.0, 0.0, 0.0 }));
	MultiplyVectorOfFloatByElement(b2, 3.21f);
	CHECK_THAT(b2, Catch::Approx(std::vector<float>{ 29.211f, 6.42f, 23.5293f, 12.8721f }));
}

TEST_CASE("Test function GetMinElementInVectorOfFloat")
{
	std::vector<float> a = {};
	std::vector<float> b = { 9.1f, 2.0f, 7.33f, 4.01f };

	REQUIRE(GetMinElementInVectorOfFloat(a) == std::nullopt);
	REQUIRE(GetMinElementInVectorOfFloat(b) == 2.0);
}

TEST_CASE("Test function MultiplyVectorOfFloatByMinElement")
{
	using namespace Catch::literals;
	std::vector<float> a{ 9.1f, 2.0f, 7.33f, 4.01f };
	
	MultiplyVectorOfFloatByMinElement(a);
	CHECK_THAT(a, Catch::Approx(std::vector<float>{ 18.2f, 4.0f, 14.66f, 8.02f }));
}
