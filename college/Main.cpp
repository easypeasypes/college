#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
void finderOfTheWord(std::string chtoto, std::string word, const int size, const int size2) {
	if (size2 > size) return;
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (chtoto[i] >= 'A' && chtoto[i] <= 'Z') {
			chtoto[i] = chtoto[i] + 32;
		}
	}
	for (int i = 0; i < size2; i++) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			word[i] = word[i] + 32;
		}
	}
	for (int i = 0; i < size; i++) {
		if (chtoto[i] == word[j]) {
			j++;
		}
		else if(j > 0) {
			i -= j;
			j = 0;
		}
		if (j == size2) {
			std::cout << "\n" << 1 << "\n";
			return;
		}
	}
}
int main() {
	SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); srand(time(NULL));
	std::string chtoto;
	std::string word;
	std::cout << "Введите текст\n";
	std::getline(std::cin, chtoto);
	const int size = chtoto.size();
	if (chtoto.size() <= 0) {
		system("cls");
		std::cout << "\nПусто в строке\n";
	}
	else if (chtoto[0] >= 'a' && chtoto[0] <= 'z') {
		chtoto[0] = chtoto[0] - 32;
	}
	for (int i = 1; i < size; i++) {
		if (chtoto[i] >= 'A' && chtoto[i] <= 'Z') {
			chtoto[i] = chtoto[i] + 32;
		}
	}
	for (int i = 0; i < size; i++) {
		if (chtoto[i] == 32) {
			i++;
			if (chtoto[i] >= 'a' && chtoto[i] <= 'z') {
				chtoto[i] = chtoto[i] - 32;
			}
		}
	}
std::cout << "\nВывод: " << chtoto << "\n" << "Введите слово, которое хотите найти: ";
std::getline(std::cin, word);
const int size2 = word.size();
finderOfTheWord(chtoto, word, size, size2);
return 0;
}