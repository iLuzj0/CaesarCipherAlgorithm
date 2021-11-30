#include<iostream>
#include<string>
#include <stdlib.h>
#include <algorithm>
#include <array>
#include <time.h>
#include "CaesarCipher.h"

int main() {
	std::string InputString;
	int LetterOffset = 0;

	CaesarCipher CaesarAlhorithm;

	std::cout << "standardowy alfabet i cyfry:" << std::endl;
	CaesarAlhorithm.PrintAlphabet(false);
	CaesarAlhorithm.PrintNumbers(false);
	
	std::cout << std::endl << "Losowo przesuniety alfabet i cyfry: " << std::endl;
	CaesarAlhorithm.PrintAlphabet(true);
	CaesarAlhorithm.PrintNumbers(true);
	
	std::cout << std::endl << "Podaj tekst do zaszyfrowania: ";
	std::cin >> InputString;

	std::string EncryptedMessage = CaesarAlhorithm.EncryptRandomAlphabet(InputString, LetterOffset);

	std::cout << "Wiadomosc po zaszyfrowaniu: " << EncryptedMessage << std::endl;
	std::cout << std::endl;
	CaesarAlhorithm.CountAlgorithUsage(InputString,EncryptedMessage);
	
	return 0;
}