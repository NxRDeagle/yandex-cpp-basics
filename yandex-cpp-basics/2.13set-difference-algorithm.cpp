#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define ACTIVE_MAIN

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
    auto it1 = first1;
    auto it2 = first2;

    while (it1 != last1) {
        // Пропускаем в B элементы, которые МЕНЬШЕ текущего элемента из A
        while (it2 != last2 && *it2 < *it1)
            ++it2;

        // Элемент из A попадает в результат если:
        // 1. B закончился (значит такого элемента точно нет в B)
        // 2. Или элемент из A МЕНЬШЕ текущего элемента из B (значит его нет в B, т.к. B отсортирован)
        if (it2 == last2 || *it1 < *it2) {
            *out = *it1; // Записываем в результат
            ++out; // Сдвигаем выходной итератор
        }
        else if (it2 != last2)  // Если элементы РАВНЫ
            ++it2;  // Пропускаем в B, т.к. элемент есть в обоих множествах
        ++it1; // Переходим к следующему элементу A
    }
    return out;
}

static void printVector(const std::vector<int>& v, const std::string& name) {
    std::cout << name << ": ";
    for (int x : v) 
        std::cout << x << " ";
    std::cout << std::endl;
}

#ifdef ACTIVE_MAIN
int main() {
    std::vector<int> A = { 1, 2, 4, 5, 6 };
    std::vector<int> B = { 2, 3, 5 };
    std::vector<int> result;

    SetDifference(A.begin(), A.end(),
        B.begin(), B.end(),
        std::back_inserter(result));

    printVector(A, "SET A");
    printVector(B, "SET B");
    printVector(result, "A \\ B");

    return 0;
}
#endif

/*
    Напишите свою реализацию стандартного алгоритма set_difference. Заголовок функции должен быть таким:

    template <typename InIter1, typename InIter2, typename OutIter>
    OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out);

    Функция должна сформировать элементы разности диапазонов [first1, last1) и [first2, last2) и записать их в последовательность,
    начинающуюся с out. Исходные диапазоны предполагаются отсортированными. Каждый элемент считается со своей кратностью.
    Функция должна вернуть итератор, который указывает за последний записанный элемент.

    В вашем решении должен быть только код этой шаблонной функции и не должно быть функции main.
    Программа должна использовать константную память и быть линейной по сложности.
    Допускается сравнивать итераторы с помощью == и !=, а также сравнивать элементы с помощью <. Использовать вызов std::set_difference нельзя.
*/
