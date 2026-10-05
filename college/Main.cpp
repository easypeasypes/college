#include <iostream>
#include <Windows.h>
int check(int year) {
    if (year % 400 == 0) {
        return 1;
    }
    if (year % 100 == 0) {
        return 0;
    }
    if (year % 4 == 0) {
        return 1;
    }
    return 0;
}
int countDays(int day, int month, int year) {
    int totalDays = 0;
    for (int i = 1; i < year; i++) {
        if (check(i) == 1) {
            totalDays = totalDays + 366;
        }
        else {
            totalDays = totalDays + 365;
        }
    }
    for (int month = 1; month < month; month++) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            totalDays = totalDays + 31;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            totalDays = totalDays + 30;
        }
        if (month == 2) {
            if (check(year) == 1) {
                totalDays = totalDays + 29;
            }
            else {
                totalDays = totalDays + 28;
            }
        }
    }
    totalDays = totalDays + day;
    return totalDays;
}
int calculateor3000(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = countDays(day1, month1, year1);
    int days2 = countDays(day2, month2, year2);
    int result = days2 - days1;
    if (result < 0) {
        result--;
    }
    return result;
}
void printDays(int finalDays) {
    std::cout << "Разница между датами в днях: " << finalDays << std::endl;
}
int calculateorArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    double avg = (double)sum / size;
    return avg;
}
void printAvg(double result) {
    std::cout << "Среднее арифметическое элементов массива: " << result << "\n";
}
void schitatel(int arr[], int size) {
    int nol = 0, pol = 0, min = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == 0) {
            nol++;
        }
        else if (arr[i] >= 1) {
            pol++;
        }
        else if (arr[i] < 0) {
            min++;
        }
    }
    std::cout << "Положительных: " << pol << " Отрицательных: " << min << " Нулей: " << nol;
}
int main()
{
    SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); srand(time(NULL));
    int dz = 0;
    std::cout << "Введите номер задания: ";
    std::cin >> dz;
    if (dz == 1) {
        system("cls");
        int day1, month1, year1;
        int day2, month2, year2;
        std::cout << "Введите первую дату (день месяц год через пробел): \n";
        std::cin >> day1;
        std::cin >> month1;
        std::cin >> year1;
        std::cout << "Введите вторую дату (день месяц год через пробел): \n";
        std::cin >> day2;
        std::cin >> month2;
        std::cin >> year2;
        int answer = calculateor3000(day1, month1, year1, day2, month2, year2);
        printDays(answer);
    }
    else if (dz == 2) {
        system("cls");
        const int size = 5;
        int count = size;
        int arr[size]{};
        for (int i = 0; i < size; i++){
            arr[i] = rand() % 11;
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        double average = calculateorArr(arr, count);
        printAvg(average);
    }
    else if (dz == 3) {
        system("cls");
        const int size = 5;
        int count = size;
        int arr[size]{};
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 5 - 2;
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        schitatel(arr, size);
        std::cout << "\n";
    }
    else {
        system("cls");
        std::cout << "Число нэ правыльно";
    }
    return 0;
}