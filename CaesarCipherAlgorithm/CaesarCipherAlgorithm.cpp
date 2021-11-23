#include<iostream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include "CaesarCipher.h"

int main() {
	int iSecret;
	srand(time(NULL));
	iSecret = rand() % 26 + 1;

	std::string InputString;
	int LetterOffset;
	CaesarCipher CaesarAlhorithm;

	std::cout << "Standardowy alfabet:" << std::endl;
	CaesarAlhorithm.PrintAlphabet(0);

	std::cout << std::endl << "Losowo przesuniety alfabet o: " << iSecret << std::endl;
	CaesarAlhorithm.PrintAlphabet(iSecret);

	std::cout << std::endl;
	std::cout << "Podaj tekst do zaszyfrowania: " << std::endl;
	std::cin >> InputString;
	std::cout << "Podaj offset: ";
	std::cin >> LetterOffset;
	//system("cls");


	std::cout << "Test przed zaszyfrowaniem: " << InputString << std::endl;

	std::cout << "Offset zaszyfrowania: " << LetterOffset << std::endl;

	std::cout << "Tekst po zaszyfrowaniu: " << CaesarAlhorithm.EncryptMessage(InputString, LetterOffset) << std::endl;

	std::cout << std::endl << "Statystyki przed szyfrowaniem:" << std::endl;

	CaesarAlhorithm.PrintCountedVariablesBeforeAlgorithm();

	std::cout << std::endl << std::endl << "Statystyki po szyfrowaniu:" << std::endl;

	CaesarAlhorithm.PrintCountedVariablesAfterAlgorithm();
	
	return 0;
}