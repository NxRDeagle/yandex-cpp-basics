#include <iostream>

#ifdef ACTIVE_MAIN
int main() {
    int number;
    std::cin >> number;

    int sum = 0;

    if (number == 0)
        sum = 0;
    else {
        // Пока число не равно 0, извлекаем последнюю цифру и добавляем её к сумме
        int temp = number;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
#endif

/*
    Вычислите сумму цифр неотрицательного целого числа.
    На вход подаётся одно неотрицательное целое число, не превосходящее 10^9
    Выведите сумму цифр этого числа.
*/