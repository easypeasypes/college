#include <iostream>
#include <Windows.h>
int main() {SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); srand(time(NULL));
    const int zapas[2]{ 300, 1000 };
    const int doptank[2]{ 0, 100 };
    const int maxkg[2]{ 2000, 3000 };
    int fuel[2][3][2]{
        {{750, 1},
         {1500, 4},
         {2000, 7}},

        {{1000, 2},
         {2000, 4},
         {3000, 6}}
    };
    int choice = 0;
    int distAB = 0, distBC = 0, weight = 0;
    std::cout << "1) Самолёт №1\nЁмкость бака - 300 литров\nПотребление топлива в зависимости от веса груза :\n- до 750 кг : 1 литр / км\n- до 1500 кг : 4 литра / км\n- до 2000 кг : 7 литров / км.\n- более 2000 кг – самолет не поднимает";
    std::cout << "\n2) Самолёт №2\nЁмкость бака - 1000 литров\nПотребление топлива в зависимости от веса груза :\n- до 1000 кг : 2 литра / км\n- до 2000 кг : 4 литра / км\n- до 3000 кг : 6 литров / км.\n- более 3000 кг – самолет не поднимает";
    std::cout << "\n\nВыберите номер самолёта (1 или 2): ";
    std::cin >> choice;
    if (choice != 1 && choice != 2) {
        std::cout << "Неверный номер самолёта" << std::endl;
        return 0;
    }
    int massivvibor = choice - 1;
    std::cout << "Введите вес груза (кг): ";
    std::cin >> weight;
    if (weight > maxkg[massivvibor] || weight <= 0) {
        std::cout << "Самолет не поднимет такой вес" << std::endl;
        return 0;
    }
    std::cout << "Введите расстояние от А до В (км): ";
    std::cin >> distAB;
    std::cout << "Введите расстояние от В до С (км): ";
    std::cin >> distBC;
    if (distAB < 0 || distBC < 0) {
        std::cout << "Расстояние не может быть в -" << std::endl;
        return 0;
    }
    int ispolzovanie = 0;
    for (int i = 0; i < 3; ++i) {
        if (weight <= fuel[massivvibor][i][0]) {
            ispolzovanie = fuel[massivvibor][i][1];
            break;
        }
    }
    int fuelAB = distAB * ispolzovanie;
    int fuelstart = zapas[massivvibor] + doptank[massivvibor];
    if (fuelAB > fuelstart) {
        std::cout << "Не хватит топлива, чтобы долететь до В" << std::endl;
        return 0;
    }
    int fuelostatok = fuelstart - fuelAB;
    if (fuelostatok > zapas[massivvibor]) {
        fuelostatok = zapas[massivvibor];
    }
    int fuelBC = distBC * ispolzovanie;
    if (fuelBC > zapas[massivvibor]) {
        std::cout << "Основного бака не хватит для участка В-С даже при полной заправке\n";
        return 0;
    }
    int refuelneed = 0;
    if (fuelostatok < fuelBC) {
        refuelneed = fuelBC - fuelostatok;
    }
    system("cls");
    std::cout << "Расход топлива: " << ispolzovanie << " л/км\n";
    std::cout << "Остаток топлива в основном баке при прилете в В (доп. бак сброшен): " << fuelostatok << " л\n";
    std::cout << "Минимальное количество топлива для дозаправки в В: " << refuelneed << " л\n";
    return 0;
}