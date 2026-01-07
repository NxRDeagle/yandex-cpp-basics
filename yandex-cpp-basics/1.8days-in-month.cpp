#include <iostream>

#ifdef ACTIVE_MAIN
int main() {
    int month, year;
    std::cin >> month >> year;

    // Проверяем, является ли год високосным
    bool is_leap = false;
    if (year % 400 == 0)
        is_leap = true;
    else if (year % 100 == 0)
        is_leap = false;
    else if (year % 4 == 0)
        is_leap = true;

    // Определяем количество дней в месяце
    int days = 0;
    switch (month) {
    case 1:  // Январь
    case 3:  // Март
    case 5:  // Май
    case 7:  // Июль
    case 8:  // Август
    case 10: // Октябрь
    case 12: // Декабрь
        days = 31;
        break;
    case 4:  // Апрель
    case 6:  // Июнь
    case 9:  // Сентябрь
    case 11: // Ноябрь
        days = 30;
        break;
    case 2:  // Февраль
        days = is_leap ? 29 : 28;
        break;
    default:
        break;
    }

    std::cout << days << std::endl;

    return 0;
}
#endif

/*
    Напишите программу, выводящую количество дней в месяце по заданному номеру месяца и году.
    При вычислении, используйте григорианский календарь.
    На вход программе подается два целых положительных числа: номер месяца (от 1 до 12) и четырёхзначный год.
    Необходимо вывести одно число — количество дней в заданном месяце.
*/