#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../HtmlEncode/HtmlLib.h"
#include <sstream>


TEST_CASE("Test function EncodeChar")
{
	REQUIRE(EncodeChar('a') == "a");
	REQUIRE(EncodeChar('B') == "B");
	REQUIRE(EncodeChar('<') == "&lt;");
	REQUIRE(EncodeChar('&') == "&amp;");
}

TEST_CASE("Test function EncodeString")
{
	std::string withoutSpecialSymb = "Hello WORLD!", withSpecialSymb = "1 < 2 && 3 > 2", empty = "";
	REQUIRE(EncodeString(withoutSpecialSymb) == withoutSpecialSymb);
	REQUIRE(EncodeString(withSpecialSymb) == "1 &lt; 2 &amp;&amp; 3 &gt; 2");
	REQUIRE(EncodeString(empty) == empty);

}

TEST_CASE("Test function PrintEncodedInputString")
{
	std::stringstream inputStream, outputStream;
	inputStream << "Hello WORLD!";

	PrintEncodedInputString(inputStream, outputStream);
	REQUIRE(outputStream.str() == inputStream.str() + "\n");

	std::stringstream inputStream1, outputStream1;
	inputStream1 << "Hello WORLD!" << "\n" << "Hello <user>!";
	
	PrintEncodedInputString(inputStream1, outputStream1);
	REQUIRE(outputStream1.str() == "Hello WORLD!\nHello &lt;user&gt;!\n");
}
