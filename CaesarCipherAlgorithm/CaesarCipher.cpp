#include "CaesarCipher.h"

void CaesarCipher::PrintAlphabet(bool bShuffle)
{
	int i = 97;
	for (auto& Letter : Alphabet)
	{
		Letter = i;
		if(!bShuffle) std::cout << " " << Letter << " |";
		i++;
	}
	if (bShuffle)
	{
		std::random_shuffle(Alphabet.begin(), Alphabet.end());
		for (auto Letter : Alphabet)
		{
			std::cout << " " << Letter << " |";
		}
	}
	std::cout << std::endl;
}
void CaesarCipher::PrintNumbers(bool bShuffle)
{
	int i = 48;
	for (auto& Number : Numbers)
	{
		Number = i;
		if (!bShuffle) std::cout << " " << Number << " |";
		i++;
	}
	if(bShuffle)
	{
		std::random_shuffle(Numbers.begin(), Numbers.end());
		for (auto Number : Numbers)
		{
			std::cout << " " << Number << " |";
		}
	}
	std::cout << std::endl;
}

void CaesarCipher::EncryptRandomAlphabet(std::string InputString, int Offset)
{
	std::ostringstream StringStream;
	for (auto LetterInString : InputString)
	{
		int Counter = 0;
		for (auto Letter : Alphabet)
		{
			if(Letter == LetterInString)
			{
				//std::cout << Counter << std::endl;

				StringStream << Alphabet[Counter + (Offset % 26)];
				//std::cout << Alphabet.;
			}
			Counter++;
		}
		
	}
	std::cout << StringStream.str();
}

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
