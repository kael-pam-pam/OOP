#include <iostream>
#include <string>
#include <optional>
#include <fstream>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
	std::string seacrhStr;
	std::string replaceStr;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cout << "Invalid arguments count.\n";
		std::cout << "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	args.seacrhStr = argv[3];
	args.replaceStr = argv[4];
	return args;
}

std::string ReplaceInLine(const std::string& inputLine, const std::string& searchString, const std::string& replaceString)
{
	if (searchString == "")
	{
		return inputLine;
	}

	std::string replacedString = "";
	size_t pos = inputLine.find(searchString);
	if (pos == std::string::npos)
	{
		replacedString = inputLine;
	}
	else
	{
		size_t oldPos = 0;
		while (pos != std::string::npos)
		{
			replacedString += inputLine.substr(oldPos, pos - oldPos) + replaceString;
			oldPos = pos + searchString.length();
			pos = inputLine.find(searchString, oldPos);
		}
		replacedString += inputLine.substr(oldPos, inputLine.length() - oldPos);
	}
	return replacedString;
}

void ReplaceInFile(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& searchString, const std::string& replaceString)
{
	std::string line;
	while (std::getline(inputFile, line))
	{
		outputFile << ReplaceInLine(line, searchString, replaceString) << "\n";
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	std::ifstream input;
	input.open(args->inputFileName);
	if (!input)
	{
		std::cout << "Failed to open '" << args->inputFileName << "' for reading\n";
		return 1;
	}

	std::ofstream output;
	output.open(args->outputFileName);
	if (!output)
	{
		std::cout << "Failed to open '" << args->outputFileName << "' for writing\n";
		return 1;
	}

	ReplaceInFile(input, output, args->seacrhStr, args->replaceStr);

	return 0;
}