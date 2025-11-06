#include <iostream>
import math;

int main() {
	int a = 2, b = 3;
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "add(a,b): " << add(a, b) << std::endl;
	std::cout << "sub(a,b): " << sub(a, b) << std::endl;
	std::cout << "mul(a,b): " << mul(a, b) << std::endl;
	std::cout << "mymath.square(b): " << mymath::square(b) << std::endl;
	std::cout << "mymath.power(a,b): " << mymath::power(a, b) << std::endl;
	return 0;
}
