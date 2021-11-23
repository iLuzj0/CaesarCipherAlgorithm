#include<iostream>
#include<string>
#include <stdlib.h>
#include <algorithm>
#include <array>
#include <time.h>
#include "CaesarCipher.h"

int main() {
	int iSecretLetter;
	int iSecretNumber;
	srand(time(NULL));
	iSecretLetter = rand() % 26 + 1;
	iSecretNumber = rand() % 10 + 1;
	//std::string InputString;
	//int LetterOffset;
	CaesarCipher CaesarAlhorithm;

	std::cout << "standardowy alfabet i cyfry:" << std::endl;
	CaesarAlhorithm.PrintAlphabet(false);
	CaesarAlhorithm.PrintNumbers(false);

	std::cout << std::endl << "Losowo przesuniety alfabet i cyfry: " << std::endl;
	CaesarAlhorithm.PrintAlphabet(true);
	CaesarAlhorithm.PrintNumbers(true);

	CaesarAlhorithm.EncryptRandomAlphabet("abc", 27);

	//std::cout << std::endl << "Podaj tekst do zaszyfrowania: ";
	//std::cin >> InputString;
	//std::cout  << "Podaj offset: ";
	//std::cin >> LetterOffset;
	////system("cls");

	//std::cout << "Tekst po zaszyfrowaniu: " << CaesarAlhorithm.EncryptMessage(InputString, LetterOffset) << std::endl;

	//std::cout << std::endl << "Statystyki przed szyfrowaniem:" << std::endl;

	//CaesarAlhorithm.PrintCountedVariablesBeforeAlgorithm();

	//std::cout << std::endl << std::endl << "Statystyki po szyfrowaniu:" << std::endl;

	//CaesarAlhorithm.PrintCountedVariablesAfterAlgorithm();
	
	return 0;
}