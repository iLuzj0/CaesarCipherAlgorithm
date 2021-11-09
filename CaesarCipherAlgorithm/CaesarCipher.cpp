#include "CaesarCipher.h"

std::string CaesarCipher::EncryptMessage(std::string InputString, int LetterOffset)
{
	int LocalOffset;
	std::string Output;
	std::ostringstream StringStream;
	for (auto& each : InputString)
	{
		BeforeAlgorithmCount[each]++;
		LocalOffset = 0;
		if (std::isdigit(each)) {
			if (LetterOffset < 0) {
				LocalOffset = 10 + (LetterOffset % 10);
			}
			else LocalOffset = LetterOffset;
			each = (each - '0' + LocalOffset) % 10 + '0';
		}
		else if (std::isupper(each)) {
			if (LetterOffset < 0) {
				LocalOffset = 26 + (LetterOffset % 26);
			}
			else LocalOffset = LetterOffset;
			each = (each - 'A' + LocalOffset) % 26 + 'A';
		}
		else if (std::islower(each)) {
			if (LetterOffset < 0) {
				LocalOffset = 26 + (LetterOffset % 26);
			}
			else LocalOffset = LetterOffset;
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
