#include "VectorOfFloat.h"
#include <iomanip>
#include <sstream>

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

void PrintVectorOfFloatToStream(std::ostream& outputStream, const std::vector<float>& vectorOfFloat)
{
	bool firstElement = true;
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

void MultiplyVectorOfFloatByMinElement(std::vector<float>& vectorOfFloat)
{
	auto minElem = GetMinElementInVectorOfFloat(vectorOfFloat);
	if (minElem)
	{
		MultiplyVectorOfFloatByElement(vectorOfFloat, minElem.value());
	}
}

void MultiplyVectorOfFloatByElement(std::vector<float>& vectorOfFloat, float element)
{
	for (auto& elem : vectorOfFloat)
	{
		elem *= element;
	}
}
