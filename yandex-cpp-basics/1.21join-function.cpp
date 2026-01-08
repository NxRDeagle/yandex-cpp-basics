#include <iostream>
#include <string>
#include <vector>

static std::string Join(const std::vector<std::string>& tokens, char delimiter) {
	std::string result = "";
	if (tokens.empty())
		return result;

	std::string token = tokens[0];
	result += token;

	for (size_t i = 1; i < tokens.size(); ++i)
		result += delimiter + tokens[i];

	return result;
}

#ifdef ACTIVE_MAIN
int main() {
	std::string delimeter, token;
	std::cin >> delimeter;

	std::vector<std::string> tokens;
	while (std::getline(std::cin, token))
		tokens.push_back(token);

	std::string result = Join(tokens, delimeter[0]);

	std::cout << result << std::endl;

	return 0;
}
#endif

/*
	Вам требуется написать функцию Join со следующим заголовком:
	std::string Join(const std::vector<std::string>& tokens, char delimiter);

	Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель.
	
	Например, Join({"What", "is", "your", "name?"}, '_') должна вернуть строку "What_is_your_name?".

	Если вектор tokens пустой, то функция должна вернуть пустую строку. Если в векторе tokens ровно один элемент, то он и должен вернуться в ответе.
*/