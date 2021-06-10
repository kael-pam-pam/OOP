#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../httpUrl/CUrlParsingError.h"
#include "../httpUrl/CHttpUrl.h"

#include <exception>

TEST_CASE("Test function RepairDocumnent")
{
	REQUIRE(RepairDocumnent("") == "/");
	REQUIRE(RepairDocumnent("about/index.html") == "/about/index.html");
	REQUIRE(RepairDocumnent("/about/index.html") == "/about/index.html");
}

TEST_CASE("Test function GetStandartPort")
{
	REQUIRE(GetStandartPort(Protocol::HTTP) == HTTP_PORT_NUMBER);
	REQUIRE(GetStandartPort(Protocol::HTTPS) == HTTPS_PORT_NUMBER);
	REQUIRE_THROWS_AS(GetStandartPort(Protocol::UNCNOWN), std::invalid_argument);
}

TEST_CASE("Test function ValidatePort")
{
	REQUIRE(ValidatePort(80) == 80);
	REQUIRE(ValidatePort(1285) == 1285);
	REQUIRE_THROWS_AS(ValidatePort(-5), std::out_of_range);
	REQUIRE_THROWS_AS(ValidatePort(65600), std::out_of_range);
}

TEST_CASE("Test function StrToPort")
{
	REQUIRE(StrToPort("123") == 123);
	REQUIRE_THROWS_AS(StrToPort("-5"), std::out_of_range);
	REQUIRE_THROWS_AS(StrToPort(""), std::invalid_argument);
}
/*
TEST_CASE("Test ")
{
	REQUIRE();
}
TEST_CASE("Test ")
{
	REQUIRE();
}
TEST_CASE("Test ")
{
	REQUIRE();
}
TEST_CASE("Test ")
{
	REQUIRE();
}
TEST_CASE("Test ")
{
	REQUIRE();
}
TEST_CASE("Test ")
{
	REQUIRE();
}
TEST_CASE("Test ")
{
	REQUIRE();
}
TEST_CASE("Test ")
{
	REQUIRE();
}
TEST_CASE("Test ")
{
	REQUIRE();
}
*/