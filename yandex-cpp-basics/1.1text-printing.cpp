#include <iostream>

#ifdef ACTIVE_MAIN
int main() {
    std::cout << "C++ is a general-purpose programming language with a bias towards systems programming that\n";
    std::cout << "  - is a better C\n";
    std::cout << "  - supports data abstraction\n";
    std::cout << "  - supports object-oriented programming\n";
    std::cout << "  - supports generic programming.";
    return 0;
}
#endif

/*
    Напишите программу, печатающую на экране первые строчки со страницы Бьярне Страуструпа про C++.
    Не потеряйте парные пробелы в начале строк и переносы в конце строк.
*/