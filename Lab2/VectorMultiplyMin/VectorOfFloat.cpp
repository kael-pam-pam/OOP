#include "VectorOfFloat.h"
#include <iomanip>
#include <sstream>
#include <algorithm>

std::vector<float> GetVectorOfFloatFromStream(std::istream& inputStream)
{
	std::vector<float> inputNumbers;
	float element;

	while (inputStream >> element)
	{
		inputNumbers.push_back(element);
	}

	return inputNumbers;
}

void PrintVectorOfFloatToStream(std::ostream& outputStream, std::vector<float> vectorOfFloat)
{
	bool firstElement = true;
	SortVectorOfFloat(vectorOfFloat);
	for (const auto& element : vectorOfFloat)
	{
		if (!firstElement)
		{
			outputStream << " ";
		}
		outputStream << std::fixed << std::setprecision(3) << element;
		firstElement = false;
	}
	outputStream << "\n";
}

std::optional<float> GetMinElementInVectorOfFloat(const std::vector<float>& vectorOfFloat)
{
	if (vectorOfFloat.size() == 0)
	{
		return std::nullopt;
	}
	return *std::min_element(vectorOfFloat.begin(), vectorOfFloat.end());
}

std::vector<float> SortVectorOfFloat(std::vector<float> vectorOfFloat)
{
	std::sort(vectorOfFloat.begin(), vectorOfFloat.end());
	return vectorOfFloat;
}

std::vector<float> MultiplyVectorOfFloatByMinElement(std::vector<float> vectorOfFloat)
{
	auto minElem = GetMinElementInVectorOfFloat(vectorOfFloat);
	if (minElem)
	{
		vectorOfFloat = MultiplyVectorOfFloatByElement(vectorOfFloat, minElem.value());
	}
	return vectorOfFloat;
}

std::vector<float> MultiplyVectorOfFloatByElement(std::vector<float> vectorOfFloat, float element)
{
	for (auto& elem : vectorOfFloat)
	{
		elem *= element;
	}
	return vectorOfFloat;
}
