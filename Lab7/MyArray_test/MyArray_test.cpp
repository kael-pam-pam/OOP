#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../MyArray/CMyArray.h"

#include <string>

TEST_CASE("Test class CMyArray")
{
	CMyArray<std::string> arr;
	REQUIRE(arr.GetSize() == 0);
	REQUIRE(arr.GetCapacity() == 0);

	arr.Append("0");
	REQUIRE(arr.GetSize() == 1);
	REQUIRE(arr.GetCapacity() == 1);
	arr.Append("1");
	REQUIRE(arr.GetSize() == 2);
	REQUIRE(arr.GetCapacity() == 2);
	
	CMyArray<std::string> arrCopy(arr);
	REQUIRE(arr.GetSize() == arrCopy.GetSize());
	REQUIRE(arr.GetCapacity() == arrCopy.GetCapacity());
	
	arr.Append("2");
	REQUIRE_THROWS_AS(arr[3], std::out_of_range);

	REQUIRE(arr[0] == "0");
	REQUIRE(arr[1] == "1");

	arr[2] = "two";
	REQUIRE(arr[2] == "two");
	REQUIRE(arr.GetSize() == 3);
	REQUIRE(arr.GetCapacity() == 4);

	arr.Resize(2);
	REQUIRE(arr.GetSize() == 2);
	REQUIRE(arr.GetCapacity() == 4);
	REQUIRE(arr[0] == "0");
	REQUIRE(arr[1] == "1");
	REQUIRE_THROWS_AS(arr[2], std::out_of_range);

	arr.Resize(5);
	REQUIRE(arr.GetSize() == 5);
	REQUIRE(arr.GetCapacity() == 5);
	REQUIRE(arr[0] == "0");
	REQUIRE(arr[1] == "1");
	REQUIRE(arr[2] == "");
	REQUIRE(arr[3] == "");
	REQUIRE(arr[4] == "");
	REQUIRE_THROWS_AS(arr[5], std::out_of_range);

	arr.Clear();
	REQUIRE(arr.GetSize() == 0);
	REQUIRE(arr.GetCapacity() == 5);
	REQUIRE_THROWS_AS(arr[0], std::out_of_range);

	arr.Append("1");
	arr.Append("2");
	arr.Append("3");
	CMyArray<std::string> newArr;
	newArr = arr;
	REQUIRE(newArr[0] == arr[0]);
	REQUIRE(newArr[1] == arr[1]);
	REQUIRE(newArr[2] == arr[2]);
	REQUIRE_THROWS_AS(arr[3], std::out_of_range);

	CMyArray<std::string> arrMove(std::move(arr));
	REQUIRE(arr.GetSize() == 0);
	REQUIRE(arrMove.GetSize() == 3);
	REQUIRE(arrMove[0] == "1");
	REQUIRE(arrMove[1] == "2");
	REQUIRE(arrMove[2] == "3");
	REQUIRE_THROWS_AS(arrMove[3], std::out_of_range);

	CMyArray<std::string> arrMove2;
	arrMove2 = std::move(arrMove);
	REQUIRE(arrMove.GetSize() == 0);
	REQUIRE(arrMove2.GetSize() == 3);
	REQUIRE(arrMove2[0] == "1");
	REQUIRE(arrMove2[1] == "2");
	REQUIRE(arrMove2[2] == "3");
	REQUIRE_THROWS_AS(arrMove2[3], std::out_of_range);
}