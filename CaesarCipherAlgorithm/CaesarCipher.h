#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <array>
#include <string>

class CaesarCipher
{
public:
	std::string EncryptMessage(std::string InputString, int LetterOffset);
	void EncryptRandomAlphabet(std::string InputString, int Offset);
	void PrintCountedVariablesAfterAlgorithm();
	void PrintCountedVariablesBeforeAlgorithm();
	void PrintAlphabet(bool bShuffle);
	void PrintNumbers(bool bShuffle);

private:
	std::string InputString;
	int AlphabetOffset;
	int NumberOffset;

	std::array<char, 26> Alphabet;
	std::array<char, 10> Numbers;
	std::map<char, int> AfterAlgorithmCount;
	std::map<char, int> BeforeAlgorithmCount;
};

