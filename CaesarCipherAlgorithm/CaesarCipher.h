#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <string>

class CaesarCipher
{
public:
	std::string EncryptMessage(std::string InputString, int LetterOffset);
	void PrintCountedVariablesAfterAlgorithm();
	void PrintCountedVariablesBeforeAlgorithm();

private:
	std::string InputString;
	int LetterOffset;
	std::map<char, int> AfterAlgorithmCount;
	std::map<char, int> BeforeAlgorithmCount;
};

