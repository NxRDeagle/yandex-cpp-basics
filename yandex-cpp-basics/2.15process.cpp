#include <iostream>
#include <algorithm>
#include <vector>

template <typename Iterator>
void PrintResults(Iterator begin, Iterator end) {
    for (auto it = begin; it != end; ++it) {
        std::cout << *it;
        if (std::next(it) != end) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;

   std::copy_if(
        data.begin(),
        data.end(),
        std::back_inserter(filtered), // Заменям filtered.begin() на std::back_inserter(filtered) для добавления элементов, тк для пустого вектора не выделено памяти
        [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end()); // Можно заменить filteredLast на filtered.end()
}

#ifdef ACTIVE_MAIN
int main() {
    std::vector<int> int_data = { -5, 3, -2, 7, 0, 1, -8, 4 };
    Process(int_data);
    return 0;
}
#endif

/*
   Андрею надо написать шаблонную функцию Process, которая обрабатывает вектор с числами некоторого типа T.
   Его функция должна вызвать другую функцию PrintResults, чтобы напечатать с определенным форматированием положительные числа из вектора.
   Функция PrintResults принимает на вход пару итераторов, как и многие алгоритмы стандартной библиотеки.
   Поэтому Андрей решил сначала скопировать нужные элементы исходного вектора в другой массив, чтобы передать его начало и конец в эту функцию. Вот код Андрея:

    #include <algorithm>
    #include <vector>

    template <typename T>
    void Process(const std::vector<T>& data) {
        std::vector<T> filtered;

        auto filteredLast = std::copy_if(
            data.begin(),
            data.end(),
            filtered.begin(),
            [](const T& x) { return x > 0; }
        );

        PrintResults(filtered.begin(), filteredLast);
    }

    Этот код почему-то не работает. Найдите ошибку и сдайте исправленное решение.
*/