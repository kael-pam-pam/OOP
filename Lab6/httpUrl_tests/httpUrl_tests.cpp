#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../httpUrl/CUrlParsingError.h"
#include "../httpUrl/CHttpUrl.h"

#include <exception>

TEST_CASE("Test function GetProtocolStr")
{
	CHttpUrl url1("http://www.ya.ru:80/about.html?id=76#main");
	REQUIRE(url1.GetProtocolStr() == "http");
	CHttpUrl url2("www.ya.ru", "/about.html", Protocol::HTTPS, 820);
	REQUIRE(url2.GetProtocolStr() == "https");
}

TEST_CASE("Test function RepairDocument")
{
	REQUIRE(RepairDocument("") == "/");
	REQUIRE(RepairDocument("about/index.html") == "/about/index.html");
	REQUIRE(RepairDocument("/about/index.html") == "/about/index.html");
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
	REQUIRE_THROWS_AS(ValidatePort(0), std::out_of_range);
	REQUIRE_THROWS_AS(ValidatePort(-5), std::out_of_range);
	REQUIRE_THROWS_AS(ValidatePort(MAX_PORT_NUMBER+1), std::out_of_range);
}

TEST_CASE("Test function StrToPort")
{
	REQUIRE(StrToPort("123") == 123);
	REQUIRE_THROWS_AS(StrToPort("0"), std::out_of_range);
	REQUIRE_THROWS_AS(StrToPort("-5"), std::out_of_range);
	REQUIRE_THROWS_AS(StrToPort(""), std::invalid_argument);
	REQUIRE_THROWS_AS(StrToPort("hello"), std::invalid_argument);
}

TEST_CASE("Test function StrToProtocol")
{
	REQUIRE(StrToProtocol("HTTP") == Protocol::HTTP);
	REQUIRE(StrToProtocol("http") == Protocol::HTTP);
	REQUIRE(StrToProtocol("https") == Protocol::HTTPS);
	REQUIRE_THROWS_AS(StrToProtocol("ht"), std::invalid_argument);
}

TEST_CASE("Test function GetPort/GetProtocol/GetDocument/GetDomain")
{
	CHttpUrl url("http://www.ya.ru:88/about.html?id=76#main");
	REQUIRE(url.GetPort() == 88);
	REQUIRE(url.GetProtocol() == Protocol::HTTP);
	REQUIRE(url.GetDocument() == "/about.html");
	REQUIRE(url.GetDomain() == "www.ya.ru");
}

TEST_CASE("Test function GetURL")
{
	CHttpUrl url1("http://www.ya.ru:80/about.html?id=76#main");
	REQUIRE(url1.GetURL() == "http://www.ya.ru/about.html");
	CHttpUrl url2("https://www.google.ru:400/index.html?page=726#head");
	REQUIRE(url2.GetURL() == "https://www.google.ru:400/index.html");
	CHttpUrl url3("https://www.google.ru");
	REQUIRE(url3.GetURL() == "https://www.google.ru/");
}

TEST_CASE("Test constructor CHttpUrl (v1)")
{
	CHttpUrl url1("www.ya.ru", "/about.html", Protocol::HTTP, 80);
	REQUIRE(url1.GetPort() == 80);
	REQUIRE(url1.GetProtocol() == Protocol::HTTP);
	REQUIRE(url1.GetDocument() == "/about.html");
	REQUIRE(url1.GetDomain() == "www.ya.ru");
	REQUIRE_THROWS_AS(CHttpUrl("", "about.html", Protocol::HTTP, 80), std::invalid_argument);
}

TEST_CASE("Test constructor CHttpUrl (v2)")
{
	CHttpUrl url1("www.ya.ru", "about.html", Protocol::HTTP);
	REQUIRE(url1.GetPort() == 80);
	REQUIRE(url1.GetProtocol() == Protocol::HTTP);
	REQUIRE(url1.GetDocument() == "/about.html");
	REQUIRE(url1.GetDomain() == "www.ya.ru");
	REQUIRE_THROWS_AS(CHttpUrl("", "about.html", Protocol::HTTP), std::invalid_argument);
}

TEST_CASE("Test constructor CHttpUrl (v3)")
{
	CHttpUrl url1("http://www.ya.ru:80/about.html?id=76#main");
	REQUIRE(url1.GetPort() == 80);
	REQUIRE(url1.GetProtocol() == Protocol::HTTP);
	REQUIRE(url1.GetDocument() == "/about.html");
	REQUIRE(url1.GetDomain() == "www.ya.ru");
	REQUIRE_THROWS_AS(CHttpUrl("htp://www.ya.ru:80/about.html?id=76#main"), CUrlParsingError);
	REQUIRE_THROWS_AS(CHttpUrl("http://www.ya.ru:65600/about.html?id=76#main"), std::out_of_range);
}

