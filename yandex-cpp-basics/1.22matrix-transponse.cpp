#include <iostream>
#include <vector>

static std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
	if (matrix.empty()) return {};

	size_t rows = matrix.size();
	size_t cols = matrix[0].size();

	std::vector<std::vector<int>> result(cols, std::vector<int>(rows));

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			result[j][i] = matrix[i][j];

	return result;
}

#ifdef ACTIVE_MAIN
int main() {
	size_t m, n;
	std::cin >> m >> n;

	std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++)
			std::cin >> matrix[i][j];

	std::vector<std::vector<int>> tMatrix = Transpose(matrix);

	for (size_t i = 0; i < m; i++) {
		for (size_t j = 0; j < n; j++)
			std::cout << tMatrix[i][j] << '\t';
		std::cout << '\n';
	}

	return 0;
}
#endif

/*
	Дана прямоугольная матрица A из m строк и n столбцов. 
	Напишите функцию, которая возвращает транспонированную матрицу:
	std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);

	Гарантируется, что вектор matrix не пуст и все его элементы имеют равную ненулевую длину.
*/