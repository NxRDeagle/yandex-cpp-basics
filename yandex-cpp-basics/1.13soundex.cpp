#include <iostream>
#include <string>
#include <cctype>

// Функция для получения цифры звучания для буквы
int getSoundexDigit(char c) {
    switch (c) {
    case 'b': case 'f': case 'p': case 'v':
        return 1;
    case 'c': case 'g': case 'j': case 'k':
    case 'q': case 's': case 'x': case 'z':
        return 2;
    case 'd': case 't':
        return 3;
    case 'l':
        return 4;
    case 'm': case 'n':
        return 5;
    case 'r':
        return 6;
    default:
        return 0; // для букв, которые удаляются
    }
}

#ifdef ACTIVE_MAIN
int main() {
    std::string word;
    std::cin >> word;

    // Шаг 1: Первая буква сохраняется
    std::string result;
    result += word[0];

    // Шаг 2: Обработка остальной части слова
    std::string digits;
    for (size_t i = 1; i < word.length(); i++) {
        int digit = getSoundexDigit(word[i]);
        if (digit != 0)
            digits += std::to_string(digit);
    }

    // Шаг 3: Удаление последовательных одинаковых цифр
    std::string uniqueDigits;
    if (!digits.empty()) {
        uniqueDigits += digits[0];
        for (size_t i = 1; i < digits.length(); i++) {
            if (digits[i] != digits[i - 1])
                uniqueDigits += digits[i];
        }
    }

    // Шаг 4: Объединяем первую букву с уникальными цифрами
    result += uniqueDigits;

    // Шаг 5: Обрезаем до 4 символов
    if (result.length() > 4)
        result = result.substr(0, 4);

    // Шаг 6: Дополняем нулями если нужно
    while (result.length() < 4)
        result += '0';

    std::cout << result << std::endl;

    return 0;
}
#endif

/*
    Известный алгоритм Soundex определяет, похожи ли два английских слова по звучанию. 
    На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.
    
    Вам требуется реализовать этот алгоритм. Он работает так:

    1. Первая буква слова сохраняется.
    2. В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;
    3. Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
    b, f, p, v: 1
    c, g, j, k, q, s, x, z: 2
    d, t: 3
    l: 4
    m, n: 5
    r: 6
    4. Любая последовательность идущих подряд одинаковых цифр сокращается до одной такой цифры.
    5. Итоговая строка обрезается до первых четырёх символов.
    6. Если длина строки получилась меньше четырёх символов, в конце добавляются нули.

    Примеры:
    ammonium → ammnm → a5555 → a5 → a500.
    implementation → implmnttn → i51455335 → i514535 → i514.

    На вход подаётся одно непустое слово из строчных латинских букв. Длина слова не превосходит 20 символов.
    Напечатайте четырёхбуквенный код, соответствующий слову.
*/