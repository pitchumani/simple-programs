#include <iostream>
#include <utility>

class A {
public:
	int member;
	// constructor
	A(int val) : member(val) {}
	// move constructor
	A(A&& arg) : member(std::move(arg.member)) {}
	// assignment constructor
	A& operator=(A&& other) {
		member = std::move(other.member);
		return *this;
	}
};

int main() {
	A obj1(10);
	A obj2(12);
	std::cout << "obj1: " << obj1.member << std::endl;
	std::cout << "obj2: " << obj2.member << std::endl;
	A obj3 = std::move(obj1);
	//A obj4(50);
	//obj4 = obj2;
	std::cout << "obj1 is moved to obj3, obj2 is assigned to obj4" << std::endl;
	std::cout << "obj1: " << obj1.member << std::endl;
	std::cout << "obj2: " << obj2.member << std::endl;
	std::cout << "obj3: " << obj3.member << std::endl;
	//std::cout << "obj4: " << obj4.member << std::endl;
	return 0;
}
