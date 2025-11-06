#include <iostream>
#include <concepts>

template <typename T>
concept Integral = std::is_integral_v<T>;

template <Integral T>
void print_integral(T value) {
    std::cout << "Integral value: " << value << std::endl;
}

int main() {
    print_integral(10);
    print_integral(3.14);
    return 0;
}
