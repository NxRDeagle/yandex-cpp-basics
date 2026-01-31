#include <vector>
#include <iostream>

template <typename T>
void Duplicate(std::vector<T>& v) {
    v.reserve(v.size() * 2);
    v.insert(v.end(), v.begin(), v.end());
}

#ifdef ACTIVE_MAIN
int main() {
    std::vector<int> vec = { 1, 2, 3 };
    Duplicate(vec);

    for (const auto& el : vec)
        std::cout << el << "\t";

    std::cout << std::endl;
    return 0;
}
#endif

/*
    Требуется написать шаблонную функцию Duplicate, которая получает на вход вектор и дублирует все его элементы в конце вектора.
    Например, из вектора с элементами 1, 2, 3 должен получиться вектор с элементами 1, 2, 3, 1, 2, 3.
    Вася написал вот такую реализацию, которая почему-то не работает:

    #include <vector>
    template <typename T>
    void Duplicate(std::vector<T>& v) {
        for (auto it = v.begin(); it != v.end(); ++it) {
            v.push_back(*it);
        }
    }

    Вам надо исправить код Васи.
    Сдайте в систему только исправленный код функции Duplicate без функции main.
    Подключите все необходимые для вашей реализации библиотеки. Заголовок функции Вася написал правильно, в этом можете не сомневаться.
*/