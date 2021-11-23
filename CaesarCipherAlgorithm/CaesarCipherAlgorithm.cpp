#include<iostream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include "CaesarCipher.h"

int main() {
	int iSecretLetter;
	int iSecretNumber;
	srand(time(NULL));
	iSecretLetter = rand() % 26 + 1;
	iSecretNumber = rand() % 10 + 1;

	std::string InputString;
	int LetterOffset;
	CaesarCipher CaesarAlhorithm;

	std::cout << "Standardowy alfabet i cyfry:" << std::endl;
	CaesarAlhorithm.PrintAlphabet(0);
	CaesarAlhorithm.PrintNumbers(0);

	std::cout << std::endl << "Losowo przesuniety alfabet i cyfry: " << std::endl;
	CaesarAlhorithm.PrintAlphabet(iSecretLetter);
	CaesarAlhorithm.PrintNumbers(iSecretNumber);
	
	std::cout << std::endl << "Podaj tekst do zaszyfrowania: ";
	std::cin >> InputString;
	std::cout  << "Podaj offset: ";
	std::cin >> LetterOffset;
	//system("cls");

	std::cout << "Tekst po zaszyfrowaniu: " << CaesarAlhorithm.EncryptMessage(InputString, LetterOffset) << std::endl;

	std::cout << std::endl << "Statystyki przed szyfrowaniem:" << std::endl;

	CaesarAlhorithm.PrintCountedVariablesBeforeAlgorithm();

	std::cout << std::endl << std::endl << "Statystyki po szyfrowaniu:" << std::endl;

	CaesarAlhorithm.PrintCountedVariablesAfterAlgorithm();
	
	return 0;
}