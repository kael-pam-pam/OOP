#define CATCH_CONFIG_MAIN  
#include <catch2/catch.hpp>
#include "../Dictionary/Dictionary.h"


TEST_CASE("Main test")
{
	Dictionary dictionary;
	bool isFileExists;
	SECTION("LoadDictionaryFromFile: note exists file")
	{
		isFileExists = LoadDictionaryFromFile("not_exists_file.txt", dictionary);
		REQUIRE_FALSE(isFileExists);
		REQUIRE(dictionary.size() == 0);
	}
	isFileExists = LoadDictionaryFromFile("dictionary_test.txt", dictionary);
	REQUIRE(isFileExists);
	REQUIRE(dictionary.find("1") != dictionary.end());
	REQUIRE(dictionary.find("one") != dictionary.end());
	REQUIRE(dictionary.find("����") != dictionary.end());
	REQUIRE(dictionary.size() == 3);

	bool isAddedNewRecord;
	SECTION("DispatcherDictionary: without add new record")
	{
		std::istringstream input("1\none\n����\n...\n");
		std::ostringstream output;

		DispatcherDictionary(input, output, isAddedNewRecord, dictionary);
		REQUIRE("> one\n> ����\n> 1\n> " == output.str());
		REQUIRE_FALSE(isAddedNewRecord);
	}
	std::istringstream input("2\n\n3\nthree\n...\n\n");
	std::ostringstream output;
	std::string outStr = R"(> ����������� ����� "2". ������� ������� ��� ������ ������ ��� ������.
> ����� "2" ���������������.
> ����������� ����� "3". ������� ������� ��� ������ ������ ��� ������.
> ����� "3" ��������� � ������� ��� "three".
> )";
	DispatcherDictionary(input, output, isAddedNewRecord, dictionary);
	REQUIRE(outStr == output.str());
	REQUIRE(isAddedNewRecord);

	std::istringstream input1("\n");
	output.str("");
	SaveDictionaryToFile(input1, output, "dictionary_test.txt", isAddedNewRecord, dictionary);
	REQUIRE("� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n> " == output.str());
}