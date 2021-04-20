#pragma once
#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

std::vector<float> GetVectorOfFloatFromStream(std::istream& inputStream);
void PrintVectorOfFloatToStream(std::ostream& outputStream, const std::vector<float>& vectorOfFloat);
void MultiplyVectorOfFloatByElement(std::vector<float>& vectorOfFloat, float element);
std::optional<float> GetMinElementInVectorOfFloat(const std::vector<float>& vectorOfFloat);
void MultiplyVectorOfFloatByMinElement(std::vector<float>& vectorOfFloat);
