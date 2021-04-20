#pragma once
#include <iostream>
#include <string>

std::string EncodeChar(char ch);
std::string EncodeString(const std::string& inputString);
void PrintEncodedInputString(std::istream& inputStream, std::ostream& outputStream);