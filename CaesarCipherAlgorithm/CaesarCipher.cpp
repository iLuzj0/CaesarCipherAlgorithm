#include "CaesarCipher.h"

void CaesarCipher::PrintAlphabet(int RandomOffset)
{
	int LocalOffset;
	if (RandomOffset != 0)
	{
		AlphabetOffset = RandomOffset;
	}
	for(int i = 97; i<=122; i++)
	{
		char a = i;
		if (RandomOffset < 0) {
			LocalOffset = 26 + (RandomOffset % 26);
		}
		else LocalOffset = RandomOffset;
		a = (a - 'a' + LocalOffset) % 26 + 'a';
		std::cout << " " << a << " |";
	}
}


std::string CaesarCipher::EncryptMessage(std::string InputString, int LetterOffset)
{
	int LocalOffset;
	int LetterOffset_Alphabet = LetterOffset + AlphabetOffset;
	std::string Output;
	std::ostringstream StringStream;
	for (auto& each : InputString)
	{
		BeforeAlgorithmCount[each]++;
		LocalOffset = 0;
		if (std::isdigit(each)) {
			if (LetterOffset_Alphabet < 0) {
				LocalOffset = 10 + (LetterOffset_Alphabet % 10);
			}
			else LocalOffset = LetterOffset_Alphabet;
			each = (each - '0' + LocalOffset) % 10 + '0';
		}
		else if (std::isupper(each)) {
			if (LetterOffset_Alphabet < 0) {
				LocalOffset = 26 + (LetterOffset_Alphabet % 26);
			}
			else LocalOffset = LetterOffset_Alphabet;
			each = (each - 'A' + LocalOffset) % 26 + 'A';
		}
		else if (std::islower(each)) {
			if (LetterOffset_Alphabet < 0) {
				LocalOffset = 26 + (LetterOffset_Alphabet % 26);
			}
			else LocalOffset = LetterOffset_Alphabet;
			each = (each - 'a' + LocalOffset) % 26 + 'a';
		}
		AfterAlgorithmCount[each]++;
		StringStream << each;
	}
	return Output = StringStream.str();
}

void CaesarCipher::PrintCountedVariablesBeforeAlgorithm()
{
	std::cout << "Liczby : |";
	for (int i = 48; i <= 57; i++)
	{
		char a = i;
		std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	std::cout << "Ilosc  : |";
	for (int i = 48; i <= 57; i++)
	{
		char a = i;
		std::cout << " " << BeforeAlgorithmCount[a] << " |";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Litery : |";
	for (int i = 97; i <= 122; i++)
	{
		char a = i;
		std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	std::cout << "Ilosc  : |";
	for (int i = 97; i <= 122; i++)
	{
		char a = i;
		std::cout << " " << BeforeAlgorithmCount[a] << " |";
	}
}

void CaesarCipher::PrintCountedVariablesAfterAlgorithm()
{
	std::cout << "Liczby : |";
	for (int i = 48; i <= 57; i++)
	{
		char a = i;
		std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	std::cout << "Ilosc  : |";
	for (int i = 48; i <= 57; i++)
	{
		char a = i;
		std::cout << " " << AfterAlgorithmCount[a] << " |";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Litery : |";
	for (int i = 97; i <= 122; i++)
	{
		char a = i;
		std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	std::cout << "Ilosc  : |";
	for (int i = 97; i <= 122; i++)
	{
		char a = i;
		std::cout << " " << AfterAlgorithmCount[a] << " |";
	}
}
