#include "HtmlLib.h"
#include <vector>
#include <algorithm>

std::string EncodeChar(char ch)
{
    static std::vector<std::pair<char, std::string>> mapSymbToHtml = { {'"', "&quot;"}, {'\'', "&apos;"}, {'<', "&lt;"}, {'>', "&gt;"}, {'&', "&amp;"} };

    std::vector<std::pair<char, std::string>>::iterator it = std::find_if(mapSymbToHtml.begin(), mapSymbToHtml.end(), [&](const auto& elem) { return (elem.first == ch); });
    if (it != mapSymbToHtml.end())
    {
        return it->second;
    }
    else
    {
        std::string original(1, ch);
        return original;
    }
}

std::string EncodeString(const std::string& inputString)
{
    std::string encodedLine = "";
    for (const auto& ch : inputString)
    {
        encodedLine += EncodeChar(ch);
    }
    return encodedLine;
}


void PrintEncodedInputString(std::istream& inputStream, std::ostream& outputStream)
{
    std::string line;
    while (std::getline(inputStream, line))
    {
        outputStream << EncodeString(line) << "\n";
    }
}