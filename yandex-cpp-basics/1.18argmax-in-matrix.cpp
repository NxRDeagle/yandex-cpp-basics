#include <iostream>
#include <vector>
#include <limits>
#define ACTIVE_MAIN

static std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
	if (matrix.empty())
		return { 0, 0 };

	int maxRow = 0, maxColumn = 0, maxElement = std::numeric_limits<int>::min();
	for (size_t  i = 0; i < matrix.size(); ++i)
		for (size_t  j = 0; j < matrix[i].size(); ++j) {
			int element = matrix[i][j];
			if (element > maxElement) {
				maxElement = element;
				maxRow = i;
				maxColumn = j;
			}
		}
	return { maxRow, maxColumn };
}

#ifdef ACTIVE_MAIN
int main() {
	size_t n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> matrix(n, std::vector<int>(k));
	for (size_t  i = 0; i < n; ++i)
		for (size_t  j = 0; j < k; ++j)
			std::cout << matrix[i][j];


	std::pair<size_t, size_t> result = MatrixArgMax(matrix);
	std::cout << result.first << " " << result.second << std::endl;

	return 0;
}
#endif

/*
	Вам требуется написать на C++ функцию со следующим заголовком:
	std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);

	Функция должна вернуть пару из индексов максимального элемента в матрице. Если максимальных элементов несколько, то нужно вернуть наименьшую такую пару.
	В первой строке двумя числами n и k задан размер матрицы. В последующих n строках вводится числовая матрица в k столбцов.
	Вывести индекс строки и столбца максимального элемента в матрице.
*/