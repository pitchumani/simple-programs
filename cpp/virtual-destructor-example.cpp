#include<iostream>

class Base {
public:
    Base() {}
    //virtual
	~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
    int *data;
public:
    Derived() : data(new int(10)) {}
    ~Derived() {
        std::cout << "Derived destructor\n";
        delete data;
    }
};

int main() {
	Base *obj = new Derived();
	delete obj;
	return 0;
}
