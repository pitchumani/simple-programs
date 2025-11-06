#include <iostream>
#include <utility>

void process(int& value) {
	std::cout << "Processing lvalue: " << value << std::endl;
}

void process(int&& value) {
	std::cout << "Processing rvalue: " << value << std::endl;
}

template <typename T>
void wrapper(T&& arg) {
	std::cout << "wrapper received: ";
	process(std::forward<T>(arg));
}

int main() {
	std::cout << "std::forward example, perfect forwarding\n";
	int x = 10;
	// calling wrapper with lvalue
	wrapper(x);
	// calling wrapper with rvalue
	wrapper(20);
	// calling wrapper with moved lvalue
	wrapper(std::move(x));
	return 0;
}
