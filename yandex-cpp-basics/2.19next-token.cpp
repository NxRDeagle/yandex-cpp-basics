#include <string_view>
#include <iostream>

bool NextToken(std::string_view& sv, char delim, std::string_view& tok) {
    if (sv.empty()) {
        return false;
    }

    auto pos = sv.find(delim);
    if (pos != sv.npos) {  // разделитель найден
        tok = sv.substr(0, pos);  // вырезаем очередной токен
        sv.remove_prefix(pos + 1);  // сдвигаем sv за разделитель
    }
    else {
        tok = sv;
        sv.remove_prefix(sv.size());  // формально тут получится пустая строка
    }
    return true;
}

#ifdef ACTIVE_MAIN
int main() {
    std::string_view sv = "Hello world and good bye";
    const char delimiter = ' ';
    std::string_view token;

    int token_num = 1;
    while (NextToken(sv, delimiter, token)) {
        std::cout << token_num++ << ": \"" << token << "\"\n";
    }

    return 0;
}
#endif

/*
   Вам надо написать функцию NextToken для выделения очередного токена в строке. Токеном считается последовательность символов до указанного символа-разделителя (или до конца строки).

   int main() {
        std::string_view sv = "Hello world and good bye";

        const char delimiter = ' ';
        std::string_view token;

        // Делим строку на токены по разделителю и перебираем эти токены:
        while (NextToken(sv, delimiter, token)) {
            // обрабатываем очередной token
            // например, печатаем его на экране:
            std::cout << token << "\n";
        }
    }


   Результатом выполнения такой программы будет
    Hello
    world
    and
    good
    bye
*/
