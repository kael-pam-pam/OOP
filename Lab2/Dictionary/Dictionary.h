#pragma once
#include <string>
#include <map>
#include <iostream>
#include <optional>

struct Args
{
	std::string fileName;
};

const std::string DELIMITER = ">";
const std::string COMMAND_DICTIONARY_EXIT = "...";
const std::string COMMAND_CANCEL_TRANSLATION = "";
using Dictionary = std::map<std::string, std::string>;

std::optional<Args> ParseArgs(int argc, char* argv[], std::ostream& outStream);
bool LoadDictionaryFromFile(const std::string& fileName, Dictionary& dictionary);
void DispatcherDictionary(std::istream& inStream, std::ostream& outStream, bool& isAddedNewRecord, Dictionary& dictionary);
void SaveDictionaryToFile(std::istream& inStream, std::ostream& outStream, const std::string& fileName, bool isAddedNewRecord, const Dictionary& dictionary);