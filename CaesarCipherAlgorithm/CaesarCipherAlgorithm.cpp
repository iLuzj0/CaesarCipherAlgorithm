#include<iostream>
#include<string>
#include <stdlib.h>
#include <algorithm>
#include <array>
#include <time.h>
#include "CaesarCipher.h"

int main() {
	std::string InputString;
	int LetterOffset;

	CaesarCipher CaesarAlhorithm;

	std::cout << "standardowy alfabet i cyfry:" << std::endl;
	CaesarAlhorithm.PrintAlphabet(false);
	CaesarAlhorithm.PrintNumbers(false);
	
	std::cout << std::endl << "Losowo przesuniety alfabet i cyfry: " << std::endl;
	CaesarAlhorithm.PrintAlphabet(true);
	CaesarAlhorithm.PrintNumbers(true);
	
	std::cout << std::endl << "Podaj tekst do zaszyfrowania: ";
	std::cin >> InputString;
	std::cout  << "Podaj offset: ";
	std::cin >> LetterOffset;

	std::string EncryptedMessage = CaesarAlhorithm.EncryptRandomAlphabet(InputString, LetterOffset);

	std::cout << EncryptedMessage;
	std::cout << std::endl;
	CaesarAlhorithm.CountAlgorithUsage(InputString,EncryptedMessage);
	
	return 0;
}