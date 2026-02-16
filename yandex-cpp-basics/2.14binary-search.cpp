#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#ifdef ACTIVE_MAIN
int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sorted_array(n);
    for (int i = 0; i < n; ++i)
        std::cin >> sorted_array[i];

    for (int i = 0; i < k; ++i) {
        int target;
        std::cin >> target;

        // Используем lower_bound для поиска первого элемента >= target
        auto it = std::lower_bound(sorted_array.begin(), sorted_array.end(), target);

        int closest;
        if (it == sorted_array.begin()) {
            closest = *it;
        }
        else if (it == sorted_array.end()) {
            closest = *(it - 1);
        }
        else {
            int right = *it;
            int left = *(it - 1);

            // Выбираем ближайший, при равенстве расстояний - меньший (левый)
            if (std::abs(right - target) < std::abs(left - target)) {
                closest = right;
            }
            else {
                closest = left;
            }
        }
        std::cout << closest << "\n";
    }
    return 0;
}
#endif

/*
   В этой задаче нужно применить функцию std::lower_bound и итераторы для быстрого поиска ближайшего элемента в отсортированном массиве.

   В первой строке входных данных содержатся натуральные числа n и k, не превосходящие 100000. 
   Во второй строке задаются n целых чисел первого массива, отсортированного по неубыванию, а в третьей строке – k целых чисел второго массива.
   Каждое число в обоих массивах по модулю не превосходит 2 * 10^9. Второй массив, в отличие от первого, не отсортирован.

   Для каждого из k чисел выведите в отдельной строке число из первого массива, наиболее близкое к данному. Если таких несколько, выведите меньшее из них.
*/
