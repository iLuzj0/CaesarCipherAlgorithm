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
	std::string EncryptRandomAlphabet(std::string InputString, int Offset);
	void CountAlgorithUsage(std::string ClearMessage, std::string Encrypted);
	void PrintAlphabet(bool bShuffle);
	void PrintNumbers(bool bShuffle);

private:
	std::string InputString;
	int AlphabetOffset;
	int NumberOffset;

	std::array<char, 26> Alphabet;
	std::array<char, 10> Numbers;
	std::array<char, 26> RandomAlphabet;
	std::array<char, 10> RandomNumbers;
	std::map<char, int> AlgorithmCount;
	std::map<char, int> AfterAlgorithmCount;
	std::map<char, int> BeforeAlgorithmCount;
};

