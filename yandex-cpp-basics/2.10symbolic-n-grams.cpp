#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#define ACTIVE_MAIN

#ifdef ACTIVE_MAIN
int main() {
    size_t m, n;
    std::cin >> m >> n;

    std::unordered_map<std::string, int> freqs;

    for (size_t i = 0; i != m; ++i) {
        std::string word;
        std::cin >> word;
        for (size_t j = n; j <= word.size(); ++j) {
            ++freqs[word.substr(j - n, n)];
        }
    }

    std::vector<std::pair<std::string, int>> sorted(freqs.begin(), freqs.end());
    std::sort(
        sorted.begin(),
        sorted.end(),
        [](const auto& p1, const auto& p2) {
            return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
        }
    );

    for (const auto& [word, freq] : sorted) {
        std::cout << word << " - " << freq << "\n";
    }
}
#endif

/*
    Будем называть символьной n-граммой последовательность из n последовательно идущих символов в одном слове в тексте. Для данного числа n подсчитайте суммарное количество каждой  n-граммы в тексте.

    В первой строке заданы два числа: m — число слов в тексте (от 1 до 100000) и n — длина n-граммы (от 1 до 5). Далее идет m слов. Можно считать, что слова отделены пробелами или переносами строк.
    Обработку пунктуации и регистра реализовывать не нужно. Читайте слова просто через std::cin >> word.

    Выведите все n-граммы, отсортированные по убыванию частоты, а в случае равных частот — лексикографически (по алфавиту). Для каждой n-граммы напечатайте также её частоту (смотрите формат в примере).
*/