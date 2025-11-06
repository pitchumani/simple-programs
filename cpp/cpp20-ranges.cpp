#include <iostream>
#include <vector>
#include <ranges>
int main() {
	std::vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};
	auto processed_numbers =
		numbers | std::views::filter([](int n) { return n % 2 == 0; })
		| std::views::transform([](int n) { return n * 2; });
	std::cout << "The list of numbers:" << std::endl;
	for (int n : numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	std::cout << "The even numbers are filtered and doubled:" << std::endl;
	for (int n : processed_numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	return 0;
}

