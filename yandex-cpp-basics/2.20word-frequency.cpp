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
    size_t k;
    std::cin >> k;

    // Подсчитываем частоты слов
    std::unordered_map<std::string, int> words;
    std::string word;
    while (std::cin >> word) {
        ++words[word];
    }

    // Переносим слова и их частоты в вектор
    std::vector<std::pair<std::string, int>> v(words.begin(), words.end());

    // Находим максимальные k элементов
    std::partial_sort(
        v.begin(),
        v.begin() + std::min(v.size(), k),  // k может оказаться больше размера вектора
        v.end(),
        [](const auto& p1, const auto& p2) { return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first); }
    );

    // Печатаем топовые слова
    for (size_t i = 0; i < k && i < v.size(); ++i) {
        const auto& [word, freq] = v[i];
        std::cout << word << "\t" << freq << "\n";
    }
}
#endif

/*
    Выведите k самых частотных слов текста и их частоты.

    В первой строке указано натуральное число k, не превосходящее 1000. Далее идут строки текста объёмом до 1 Mб. Слова в тексте разделены пробелами или переводами строк. Различать регистр и обрабатывать пунктуацию не нужно.

    В выводе должно быть не более k самых частотных слов текста. Через табуляцию после слова напечатайте его частоту. Слова должны быть упрядочены по убыванию частоты, а при равенстве частот — по алфавиту.
*/