#pragma once
#include <iostream>
#include <vector>
#include <optional>

std::vector<float> GetVectorOfFloatFromStream(std::istream& inputStream);
void PrintVectorOfFloatToStream(std::ostream& outputStream, std::vector<float> vectorOfFloat);
std::vector<float> MultiplyVectorOfFloatByElement(std::vector<float> vectorOfFloat, float element);
std::optional<float> GetMinElementInVectorOfFloat(const std::vector<float>& vectorOfFloat);
std::vector<float> SortVectorOfFloat(std::vector<float> vectorOfFloat);
std::vector<float> MultiplyVectorOfFloatByMinElement(std::vector<float> vectorOfFloat);
