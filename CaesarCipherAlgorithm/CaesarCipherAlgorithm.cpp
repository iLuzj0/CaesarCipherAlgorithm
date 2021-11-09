#include<iostream>
#include<string>

int main() {
	std::string x;
	int offset;
	int boffset;

	std::string encrypted;
	std::cout << "Podaj tekst do zaszyfrowania: " << std::endl;
	std::cin >> x;
	std::cout << "Podaj offset: ";
	std::cin >> offset;
	std::cout << "Tekst po zaszyfrowaniu: ";
	for (auto& each : x)
	{
		boffset = 0;
		if (std::isdigit(each)) {
			if (offset < 0) {
				boffset = 10 + (offset % 10);
			}
			else boffset = offset;
			each = (each - '0' + boffset) % 10 + '0';
		}
		else if (std::isupper(each)) {
			if (offset < 0) {
				boffset = 26 + (offset % 26);
			}
			else boffset = offset;
			each = (each - 'A' + boffset) % 26 + 'A';
		}
		else if (std::islower(each)) {
			if (offset < 0) {
				boffset = 26 + (offset % 26);
			}
			else boffset = offset;
			each = (each - 'a' + boffset) % 26 + 'a';
		}

		std::cout << each;
	}

	return 0;
}