#include <iostream>
#include <typeinfo>

class base {
public:
    virtual ~base() {}
};

class derived : public base {
};

int main() {
    base* base_ptr = new derived();
    std::cout << "Type of base_ptr: "
              << typeid(*base_ptr).name() << std::endl;
    delete base_ptr;
    return 0;
}
