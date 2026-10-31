#include <iostream>
#include <Windows.h>
#include <string>
//				1 Функция выделения динамической памяти для указателя
void DynMem(int size, int*& ptr) {
	ptr = new int[size];
}
//				2 Функция заполнения динамического массива случайными числами
void RanNum(int size, int*& ptr) {
	for (int i = 0; i < size; i++){
		ptr[i] = rand() % 1001;
	}
}
//				3 Функция печати динамического массива 
void CoutArr(int size, int*& ptr) {
	for (int i = 0; i < size; i++){
		std::cout << ptr[i] << " ";
	}
}
//				4 Функция удаления динамического массива 
void DelArr(int*& ptr) {
	delete[] ptr;
	ptr = nullptr;
}
//				5 Функция добавления элемента в конец массива
void Last(int& size, int*& ptr , int lastEl) {
	int* newPtr = new int[size + 1];
	for (int i = 0; i < size; i++){
		newPtr[i] = ptr[i];
	}
	newPtr[size] = lastEl;
	delete[] ptr;
	ptr = newPtr;
	size++;
}
//				6 Функция вставки элемента по указанному индексу 
void Inpt(int& size, int*& ptr,int lastEl, int el) {
	int* newPtr = new int[size + 1];
	int index = 0;
	for (int i = 0; i < size + 1; i++){
		if (i == el) {
			newPtr[i] = lastEl;
		}
		else {
			newPtr[i] = ptr[index];
			index++;
		}
	}
	delete[] ptr;
	ptr = newPtr;
	size++;
}
//				7 Функция удаления элемента по указанному индексу
void InptDel(int& size, int*& ptr, int lastEl, int el) {
	if (el < 0 || el >= size || size <= 0) { return; }
	int* newPtr = new int[size - 1];
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (i == el) {
			;
		}
		else {
			newPtr[index] = ptr[i];
			index++;
		}
	}
	delete[] ptr;
	ptr = newPtr;
	size--;
}
int main() {
	SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); srand(time(NULL));
	int size = 5;
	int* ptr = nullptr;
	int lastEl = 0;
	int el = 0;
	DynMem(size, ptr);
	RanNum(size, ptr);
	std::cout << "\t\t\t\t------------111 + 222 + 333------------ " << "\n";
	CoutArr(size, ptr);
	std::cout << "\n \t \t \t \t------------------555------------------ " << "\n";
	std::cout << "Введите что-нибудь, что добавится в конец массива\n";
	std::cin >> lastEl;
	Last(size, ptr, lastEl);
	CoutArr(size, ptr);
	std::cout << "\n \t \t \t \t------------------666------------------ " << "\n";
	std::cout << "Введите под какой номер хотите влепить в массив свой элемент\n";
	std::cin >> el;
	Inpt(size, ptr, lastEl, el);
	CoutArr(size, ptr);
	std::cout << "\n \t \t \t \t------------------777------------------ " << "\n";
	std::cout << "Введите под какой номер хотите удалить в массиве элемент\n";
	std::cin >> el;
	InptDel(size, ptr, lastEl, el);
	CoutArr(size, ptr);
	ptr = nullptr;
return 0;
}