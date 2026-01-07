#include <iostream>
#include <string>

#ifdef ACTIVE_MAIN
int main() {
    std::string s;
    std::getline(std::cin, s);

    int left = 0;
    int right = s.length() - 1;
    bool is_palindrome = true;

    while (left < right) {
        // Пропускаем пробелы слева
        while (left < right && s[left] == ' ') {
            left++;
        }
        // Пропускаем пробелы справа
        while (left < right && s[right] == ' ') {
            right--;
        }

        // Сравниваем символы
        if (s[left] != s[right]) {
            is_palindrome = false;
            break;
        }

        left++;
        right--;
    }

    std::cout << (is_palindrome ? "YES" : "NO") << std::endl;

    return 0;
}
#endif

/*
    Дана строка из строчных латинских букв и пробелов. Проверьте, является ли она палиндромом без учета пробелов.
    На вход подается одна строка. В строке могут быть пробелы. Подряд может идти произвольное число пробелов. Длина строки не превосходит 100.
    Представьте, что из строки удалили все пробелы. Необходимо вывести YES, если полученная строка — палиндром, и NO в противном случае.
*/