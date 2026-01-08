#include <iostream>
#include <string>
#include <vector>
#include <sstream>

static std::vector<std::string> Split(const std::string& str, char delimiter) {
	std::vector<std::string> result;
	std::string word;
	std::istringstream wordStream(str);
	while (std::getline(wordStream, word, delimiter))
		result.push_back(word);

	if (!str.empty() && str.back() == delimiter)
		result.push_back("");

	return result;
}

#ifdef ACTIVE_MAIN
int main() {
	std::string str, delimeter;
	std::cin >> str >> delimeter;

	std::vector<std::string> result = Split(str, delimeter[0]);
	for (const auto& word : result)
		std::cout << word << std::endl;

	return 0;
}
#endif

/*
	Вам требуется написать функцию со следующим заголовком:
	std::vector<std::string> Split(const std::string& str, char delimiter);

	Функция должна вернуть вектор строк, полученный разбиением строки str на части по указанному символу-разделителю delimiter.
	Если разделитель встретился в начале или в конце строки str, то в начале (соответственно, в конце) вектора с результатом должна быть пустая строка.
	Если два разделителя встретились рядом, то пустая строка между ними тоже должна попасть в ответ. 
	Для пустой строки надо вернуть вектор, содержащий одну пустую строку.

	Например, Split("What_is_your_name?", '_') должна вернуть вектор из строк What, is, your и name?.
*/