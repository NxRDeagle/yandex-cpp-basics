#include <iostream>
#include <string>
#include <set>
#include <map>

#ifdef ACTIVE_MAIN
int main() {
    std::string word;
    int wordsCount = 0;
    std::map<char, int> letterCount;
    while (std::cin >> word) {
        std::set<char> uniqueLetters;
        for (char c : word)
            uniqueLetters.insert(c);

        ++wordsCount;

        for (char c : uniqueLetters)
            ++letterCount[c];
    }

    for (const auto& [letter, count] : letterCount)
        if (count == wordsCount)
            std::cout << letter;
    
    return 0;
}
#endif

/*
    Вам даны слова. Выведите в алфавитном порядке список общих букв всех слов.
    На вход поступают слова (по одному в строке), состоящие из маленьких латинских букв алфавита. Длина слов не превосходит 100 символов, а количество слов не превосходит 1000.
    Выведите в алфавитном порядке без пробелов список букв, которые присутствуют в каждом слове.
*/