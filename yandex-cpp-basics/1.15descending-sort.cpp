#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifdef ACTIVE_MAIN
int main() {
    std::vector<std::string> lines;
    std::string line;

    // Читаем строки до конца ввода
    while (std::getline(std::cin, line))
        lines.push_back(line);

    // Сортируем строки по убыванию
    std::sort(lines.begin(), lines.end(), std::greater<std::string>());

    // Выводим отсортированные строки
    for (const auto& s : lines)
        std::cout << s << std::endl;

    return 0;
}
#endif

/*
    Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.
    Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII с кодами от 32 до 126, длина строки не превосходит 100.
    Напечатайте строки в отсортированном по убыванию порядке. 
    Для сравнения строк друг с другом достаточно использовать стандартные операторы сравнения, определённые для std::string.
*/