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
	std::ostringstream LetterStream;
	std::ostringstream NumberStream;
	int Counter = 0;
	int CounterNum = 0;
	for (auto LetterInString : InputString)
	{
		Counter = 0;
		for (auto Letter : Alphabet)
		{
			if(Letter == LetterInString)
			{
				LetterStream << Alphabet[(Counter + (Offset % 26))%26];
			}
			Counter++;
		}
	}
	for (auto input_string : InputString)
	{
		for (auto number : Numbers)
		{
			if(number == input_string)
			{
				NumberStream << Numbers[(CounterNum + (Offset % 10))%10];
			}
			CounterNum++;
		}
	}

	return LetterStream.str().append(NumberStream.str());
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
	for (int j = 48; j <= 57; j++)
	{
		char a = j;
		for (auto Letter : ClearMessage)
		{
			if (a == Letter)
				AlgorithmCount[a]++;
		}
		std::cout << " " << AlgorithmCount[a] << " |";
	}

	std::cout << std::endl << "Litery zaszyfrowane: " << std::endl;
	AlgorithmCount.clear();
	for (int z = 97; z <= 122; z++)
	{
		char a = z;
		if (islower(a))
			std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	for (int y = 97; y <= 122; y++)
	{
		char a = y;
		for (auto Letter : Encrypted)
		{
			if (a == Letter)
				AlgorithmCount[a]++;
		}
		if (islower(a))
			std::cout << " " << AlgorithmCount[a] << " |";
	}

	std::cout << std::endl << "Cyfry zaszyfrowane: " << std::endl;

	for (int o = 48; o <= 57; o++)
	{
		char a = o;
		std::cout << " " << a << " |";
	}
	std::cout << std::endl;
	for (int m = 48; m <= 57; m++)
	{
		char a = m;
		for (auto Letter : Encrypted)
		{
			if (a == Letter)
				AlgorithmCount[a]++;
		}
		std::cout << " " << AlgorithmCount[a] << " |";
	}
}