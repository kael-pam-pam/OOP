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
	REQUIRE(dictionary.find("один") != dictionary.end());
	REQUIRE(dictionary.size() == 3);

	bool isAddedNewRecord;
	SECTION("DispatcherDictionary: without add new record")
	{
		std::istringstream input("1\none\nодин\n...\n");
		std::ostringstream output;

		DispatcherDictionary(input, output, isAddedNewRecord, dictionary);
		REQUIRE("> one\n> один\n> 1\n> " == output.str());
		REQUIRE_FALSE(isAddedNewRecord);
	}
	std::istringstream input("2\n\n3\nthree\n...\n\n");
	std::ostringstream output;
	std::string outStr = R"(> Неизвестное слово "2". Введите перевод или пустую строку для отказа.
> Слово "2" проигнорировано.
> Неизвестное слово "3". Введите перевод или пустую строку для отказа.
> Слово "3" сохранено в словаре как "three".
> )";
	DispatcherDictionary(input, output, isAddedNewRecord, dictionary);
	REQUIRE(outStr == output.str());
	REQUIRE(isAddedNewRecord);

	std::istringstream input1("\n");
	output.str("");
	SaveDictionaryToFile(input1, output, "dictionary_test.txt", isAddedNewRecord, dictionary);
	REQUIRE("В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n> " == output.str());
}