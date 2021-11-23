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

std::string CaesarCipher::EncryptRandomAlphabet(std::string InputString, int Offset)
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
		Counter = 0;
		for (auto Number : Numbers)
		{
			if (Number == LetterInString)
			{
				//std::cout << Counter << std::endl;

				StringStream << Numbers[Counter + (Offset % 10)];
				//std::cout << Alphabet.;
			}
			Counter++;
		}
	}
	return StringStream.str();
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

void CaesarCipher::CountAlgorithUsage(std::string ClearMessage, std::string Encrypted)
{
	std::cout << "Litery: " << std::endl;
	
	for(int i = 97; i <= 122; i++)
	{
		char a = i;
		if(islower(a))
		std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	for (int i = 97; i <= 122; i++)
	{
		char a = i;
		for (auto Letter : ClearMessage)
		{
			if(a == Letter)
			AlgorithmCount[a]++;
		}
		if (islower(a))
		std::cout << " " << AlgorithmCount[a] << " |";
	}

	std::cout << std::endl << "Cyfry: " << std::endl;

	for (int i = 48; i <= 57; i++)
	{
		char a = i;
		std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	for (int i = 48; i <= 57; i++)
	{
		char a = i;
		for (auto Letter : ClearMessage)
		{
			if (a == Letter)
				AlgorithmCount[a]++;
		}
		std::cout << " " << AlgorithmCount[a] << " |";
	}

	std::cout << std::endl << "Litery zaszyfrowane: " << std::endl;
	AlgorithmCount.clear();
	for (int i = 97; i <= 122; i++)
	{
		char a = i;
		if (islower(a))
			std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	for (int i = 97; i <= 122; i++)
	{
		char a = i;
		for (auto Letter : Encrypted)
		{
			if (a == Letter)
				AlgorithmCount[a]++;
		}
		if (islower(a))
			std::cout << " " << AlgorithmCount[a] << " |";
	}

	std::cout << std::endl << "Cyfry zaszyfrowane: " << std::endl;

	for (int i = 48; i <= 57; i++)
	{
		char a = i;
		std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	for (int i = 48; i <= 57; i++)
	{
		char a = i;
		for (auto Letter : Encrypted)
		{
			if (a == Letter)
				AlgorithmCount[a]++;
		}
		std::cout << " " << AlgorithmCount[a] << " |";
	}
}