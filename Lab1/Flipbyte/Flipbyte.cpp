#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

struct Args
{
	std::string inputStrNumber;
};

struct ConvertResult
{
	unsigned char number;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count.\n";
		std::cout << "Usage: flipbyte.exe <input number>\n";
		return std::nullopt;
	}
	Args args;
	args.inputStrNumber = argv[1];
	return args;
}

std::optional<ConvertResult> ConvertToInt(const std::string& strNumber)
{
	size_t pos;
	int res;
	try
	{
		res = std::stoi(strNumber, &pos, 10);
		if (res < 0 || res > 255)
		{
			throw std::out_of_range("Invalid argument");
		}
		if (pos != strNumber.length())
		{
			throw std::invalid_argument("Invalid argument");
		}
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid argument.\n";
		std::cout << "Argument must be a number\n";
		return std::nullopt;
	}
	catch (std::out_of_range)
	{
		std::cout << "Argument out of range.\n";
		std::cout << "Input number must be in the range from 0 to 255\n";
		return std::nullopt;
	}

	ConvertResult args;
	args.number = res;
	return args;
}

unsigned char ReverseBytes(const unsigned char& number)
{
	return ((number & 0x1) << 7) | ((number & 0x2) << 5) | ((number & 0x4) << 3) | ((number & 0x8) << 1) | ((number & 0x10) >> 1) | ((number & 0x20) >> 3) | ((number & 0x40) >> 5) | ((number & 0x80) >> 7);
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	auto ConvertResult = ConvertToInt(args->inputStrNumber);
	if (!ConvertResult)
	{
		return 1;
	}

	std::cout << static_cast<int>(ReverseBytes(ConvertResult->number)) << "\n";
	return 0;
}
