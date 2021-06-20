#include "Dictionary.h"
#include <fstream>

std::optional<Args> ParseArgs(int argc, char* argv[], std::ostream& outStream)
{
	if (argc != 2)
	{
		outStream << "Invalid arguments count.\n";
		outStream << "Usage: Dictionary.exe <input file name>\n";
		return std::nullopt;
	}
	Args args;
	args.fileName = argv[1];
	return args;
}

bool LoadDictionaryFromFile(const std::string& fileName, Dictionary& dictionary)
{
	bool isFileExists = false;
	const int offset = 1;
	std::ifstream input;

	input.open(fileName);
	if (input)
	{
		std::string line;
		while (getline(input, line))
		{
			size_t posBeforeWord, posBeforeTranslation;
			if (((posBeforeWord = line.find(DELIMITER)) == 0) && ((posBeforeTranslation = line.find(DELIMITER, DELIMITER.length())) != std::string::npos))
			{
				dictionary.insert({ line.substr(posBeforeWord + offset, posBeforeTranslation - offset), line.substr(posBeforeTranslation + offset) });
			}
		}
		input.close();
		isFileExists = true;
	}

	return isFileExists;
}

void DispatcherDictionary(std::istream& inStream, std::ostream& outStream, bool& isAddedNewRecord, Dictionary& dictionary)
{
	std::string inputWord;
	while (inputWord != COMMAND_DICTIONARY_EXIT)
	{
		outStream << "> ";
		getline(inStream, inputWord);
		if (inputWord == COMMAND_DICTIONARY_EXIT)
		{
			break;
		}
		if (dictionary.find(inputWord) != dictionary.end())
		{
			outStream << dictionary[inputWord];
		}
		else
		{
			std::string inputTranslation;
			outStream << "Неизвестное слово \"" << inputWord << "\". Введите перевод или пустую строку для отказа.\n> ";
			getline(inStream, inputTranslation);
			if (inputTranslation == COMMAND_CANCEL_TRANSLATION)
			{
				outStream << "Слово \"" << inputWord << "\" проигнорировано.";
			}
			else
			{
				dictionary.insert({ inputWord, inputTranslation });
				isAddedNewRecord = true;
				outStream << "Слово \"" << inputWord << "\" сохранено в словаре как \"" << inputTranslation << "\".";
			}
		}
		outStream << "\n";
	}
}

void SaveDictionaryToFile(std::istream& inStream, std::ostream& outStream, const std::string& fileName, bool isAddedNewRecord, const Dictionary& dictionary)
{
	if (!isAddedNewRecord)
	{
		return;
	}

	outStream << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n> ";
	std::string inpChoisee;
	getline(inStream, inpChoisee);
	if (inpChoisee == "y" || inpChoisee == "Y")
	{
		std::ofstream output(fileName);
		if (output.is_open())
		{
			for (auto elem : dictionary)
			{
				output << DELIMITER << elem.first << DELIMITER << elem.second << "\n";
			}
			output.flush();
			output.close();
		}
		else
		{
			outStream << "Ошибка. Данные не были сохраненый в файл.";
		}
	}
}
