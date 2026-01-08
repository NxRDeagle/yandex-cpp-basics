#include <iostream>
#include <string>
#include <vector>

static std::string CommonPrefix(const std::string& first, const std::string& second) {
	size_t i = 0;
	while (i != first.size() && i != second.size() && first[i] == second[i])
		++i;
	return first.substr(0, i);
}

static std::string CommonPrefix(const std::vector<std::string>& words) {
	if (words.empty())
		return "";

	std::string prefix = words[0];
	for (size_t i = 1; i != words.size() && !prefix.empty(); ++i)
		prefix = CommonPrefix(prefix, words[i]);
	return prefix;
}

#ifdef ACTIVE_MAIN
int main() {
	std::vector<std::string> words;
	std::string word;
	while (std::getline(std::cin, word))
		words.push_back(word);

	std::cout << CommonPrefix(words);

	return 0;
}
#endif

/*
	Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе words:
	std::string CommonPrefix(const std::vector<std::string>& words);
	Например, для пустого вектора функция должна вернуть пустую строку, а для вектора из строк "apple", "apricot" и "application" — строку "ap".
	В решении не должно быть функции main: она будет в нашей тестирующей программе. Подключите необходимые библиотеки и напишите код функции CommonPrefix.
*/