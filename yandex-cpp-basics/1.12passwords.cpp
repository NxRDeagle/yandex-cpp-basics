#include <iostream>
#include <string>
#include <cctype>

#ifdef ACTIVE_MAIN
int main() {
    std::string password;
    std::getline(std::cin, password);

    // Проверка длины
    if (password.length() < 8 || password.length() > 14) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasOther = false;

    // Проверка каждого символа
    for (char c : password) {
        // Проверка диапазона ASCII кодов (33-126)
        if (c < 33 || c > 126) {
            std::cout << "NO" << std::endl;
            return 0;
        }

        // Проверка класса символа
        if (std::isupper(c)) {
            hasUpper = true;
        }
        else if (std::islower(c)) {
            hasLower = true;
        }
        else if (std::isdigit(c)) {
            hasDigit = true;
        }
        else {
            hasOther = true;
        }
    }

    // Подсчёт количества разных классов
    int classCount = 0;
    if (hasUpper) classCount++;
    if (hasLower) classCount++;
    if (hasDigit) classCount++;
    if (hasOther) classCount++;

    // Проверка, что есть минимум 3 класса
    if (classCount >= 3) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
#endif

/*
    Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
    * состоять из символов таблицы ASCII с кодами от 33 до 126;
    * быть не короче 8 символов и не длиннее 14;
    * из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие символы — в пароле должны присутствовать не менее трёх любых.
    Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.
    Выведите YES, если пароль удовлетворяет требованиям, и NO в противном случае.
*/