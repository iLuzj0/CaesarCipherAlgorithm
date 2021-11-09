#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <string>

class CaesarCipher
{
public:
	std::string EncryptMessage(std::string InputString, int LetterOffset);
	void PrintCountedVariables();

private:
	std::string InputString;
	int LetterOffset;
	std::map<char, int> BeforeAlgorithmCount;
	std::map<char, int> AfterAlgorithmCount;
};

