#include <iostream>
#include <unordered_set>

#ifdef ACTIVE_MAIN
int main() {
    int value;
    std::unordered_set<int> data;
    while (std::cin >> value) {
        if (data.contains(value))
            std::cout << "YES" << std::endl;
        else {
            std::cout << "NO" << std::endl;
            data.insert(value);
        }
    }

    return 0;
}
#endif

/*
    На вход подаётся последовательность целых чисел. Для каждого числа выведите в отдельной строке слово YES, если это число ранее встречалось в последовательности, и NO, если не встречалось.
    Вводится список чисел. Все числа списка находятся на одной строке и разделены пробелом. Каждое число представимо типом int.
*/