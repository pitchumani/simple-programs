#include <iostream>
#include <compare>

struct Point {
	int x;
	int y;
	auto operator<=>(const Point&) const = default;
};

int main() {
	Point p1{1,2};
	Point p2{1,3};
	Point p3{1,2};

	std::cout << "p1{1,2} < p2{1,3}: " << (p1 < p2) << std::endl;
	std::cout << "p1{1,2} == p3{1,2}: " << (p1 == p3) << std::endl;
	return 0;
}
