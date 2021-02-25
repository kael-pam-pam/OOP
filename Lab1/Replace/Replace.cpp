
#include <fstream>
#include <iostream>
#include <string>

std::string replace(const std::string& inputLine, const std::string& searchString, const std::string& replaceString)
{
	std::string replacedString = inputLine;
	if (searchString == "")
	{
		return replacedString;
	}

	size_t pos = replacedString.find(searchString);
	while (pos != std::string::npos)
	{
		replacedString.erase(pos, searchString.length());
		replacedString.insert(pos, replaceString);
		pos = replacedString.find(searchString, pos + replaceString.length());
	}
	return replacedString;
}

void readAndReplace(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& searchString, const std::string& replaceString)
{
	std::string line;
	while (std::getline(inputFile, line))
	{
		outputFile << replace(line, searchString, replaceString) << "\n";
	}
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cout << "Invalid count arguments.\n";
		return 1;
	}

	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string searchString, replaceString;

	inputFile.open(argv[1]);
	if (!inputFile)
	{
		std::cout << "Input file not open!\n";
		return 1;
	}

	outputFile.open(argv[2]);
	if (!outputFile)
	{
		std::cout << "Output file not open!\n";
		return 1;
	}

	searchString = argv[3];
	replaceString = argv[4];

	readAndReplace(inputFile, outputFile, searchString, replaceString);

	inputFile.close();
	outputFile.close();

	return 0;
}
