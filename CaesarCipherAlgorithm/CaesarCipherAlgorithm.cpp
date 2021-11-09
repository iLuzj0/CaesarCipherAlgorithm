#include<iostream>
#include<string>
#include "CaesarCipher.h"

int main() {

	std::string InputString;
	int LetterOffset;
	CaesarCipher CaesarAlhorithm;
	std::cout << "Podaj tekst do zaszyfrowania: " << std::endl;
	std::cin >> InputString;
	std::cout << "Podaj offset: ";
	std::cin >> LetterOffset;

	std::cout << "Tekst po zaszyfrowaniu: " << CaesarAlhorithm.EncryptMessage(InputString, LetterOffset) << std::endl;

	CaesarAlhorithm.PrintCountedVariables();
	
	return 0;
}