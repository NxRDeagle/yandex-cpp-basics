#include <iostream>
#include <vector>
#include <algorithm>
#define ACTIVE_MAIN

struct Point {
private: 
	int _distance;

public:
	int x, y;

	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
		_distance = x * x + y * y;
	}

	int distance() const {
		return _distance;
	}
};

#ifdef ACTIVE_MAIN
int main() {
	int n, x, y;
	std::cin >> n;

	std::vector<Point> points;
	points.reserve(n); // Резервируем память, но не создаем объекты

	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		points.emplace_back(x, y);  // Создаем объект прямо в векторе
	}

	std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
		return a.distance() < b.distance();
		}
	);

	for (const auto& p : points)
		std::cout << p.x << " " << p.y << std::endl;

	return 0;
}
#endif

/*
	Вам даны координаты точек на плоскости. Выведите эти точки в порядке возрастания расстояний до начала координат.

	Сначала задано количество точек n. Затем идет последовательность из n строк, каждая из которых содержит два целых числа — координаты точки. 
	Величина n не превосходит 100. Координаты точек по модулю не превосходят 1000.

	Выведите через пробел кординаты точек в порядке возрастания расстояний до начала координат. После каждой пары координат печатайте перевод строки.
*/