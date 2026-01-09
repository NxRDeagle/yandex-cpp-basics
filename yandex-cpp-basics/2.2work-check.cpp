#include <iostream>
#include <vector>
#include <string>

const std::string TOP = "top";
const std::string BOTTOM = "bottom";

#ifdef ACTIVE_MAIN
int main() {
	int i = 0, n, num, m;
	std::cin >> n;

	std::string input, surname, position;
	std::vector<std::string> list;
	while (i < n) {
		std::cin >> surname >> position;
		if (position == TOP)
			list.insert(list.begin(), surname);
		else if (position == BOTTOM)
			list.push_back(surname);
		else break;
		i++;
	}

	i = 0;
	std::cin >> m;

	std::vector<int> checkPositions;
	while (i < m) {
		std::cin >> num;
		checkPositions.push_back(num);
		i++;
	}

	for (const auto& pos : checkPositions)
		std::cout << list[pos - 1] << std::endl;

	return 0;
}
#endif

/*
	Первая строка содержит одно натуральное число N, не превосходящее 10000, — число студентов.
	Каждая из последующих N строк содержит фамилию студента — строку из латинских букв длиной от 2 до 10 символов,
	и через пробел слово top или bottom — положил этот студент свою работу сверху или снизу.

	Следующая строка содержит одно целое число M от 0 до 10000 — для какого числа работ нужно определить их автора.

	Следующие M строк содержат по одному числу xi от 1 до N — номер в стопке очередной интересующей нас работы.

	Выведите M строк. В i-й строке выведите фамилию студента, чья работа будет проверена xi-й по счёту.
*/