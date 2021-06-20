#include "Dictionary.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto args = ParseArgs(argc, argv, std::cout);
	if (!args)
	{
		return 1;
	}

	Dictionary dictionary;
	bool isFileExists = LoadDictionaryFromFile(args->fileName, dictionary);

	bool isAddedNewRecord = false;
	DispatcherDictionary(std::cin, std::cout, isAddedNewRecord, dictionary);

	SaveDictionaryToFile(std::cin, std::cout, args->fileName, isAddedNewRecord, dictionary);
	
	return 0;
}