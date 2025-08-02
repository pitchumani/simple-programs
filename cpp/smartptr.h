#ifndef SMARTPTR_H_
#define SMARTPTR_H_

#include <exception>
#include <iostream>

using namespace std;

template <typename T>
class sharedptr {
    // pointer to the destination type towhich the sharedptr is being created
    T* ptr = nullptr;
    // pointer to reference count, allocate it in heap and share it with all copies
    int* ref_count = nullptr;
    // constructor is private to avoid creating objects using constructor
    sharedptr(T* p) : ptr(p), ref_count(new int(1)) {}

public:
    // static method to create instance
    static sharedptr<T> make() {
        return sharedptr(new T());
    }
    
    // copy constructor
    // copy and increase the reference count in all copies
    sharedptr(const sharedptr& other) :
        ptr(other.ptr), ref_count(other.ref_count) {
        ++(*other.ref_count);
    }
    
    // assignment operator
    sharedptr& operator=(const sharedptr& rhs) {
        // if the same object assignment, return the same
        if (this == &rhs) {
            return *this;
        }

        // keep only one resource for pointer and ref count
        // if lhs ref count is one, delete the resources, use from rhs
        if (ref_count && *ref_count == 1) {
            delete ptr;
            delete ref_count;
        }
        ptr = rhs.ptr;
        ref_count = rhs.ref_count;
        // increase the reference count as lhs got another reference
        ++(*ref_count);
        return *this;
    }

    // count function to get the references count
    int count() const {
        return ref_count ? *ref_count : 0;
    }

    // destructor
    // check the reference counts and delete the resources at the end
    ~sharedptr() {
        if (ref_count && (--(*ref_count) == 0)) {
            delete ptr;
            delete ref_count;
        }
    }

    // get the raw pointer
    T* get() { return ptr; }
};

#endif  // SMARTPTR_H_
