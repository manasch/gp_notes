#include <iostream>
#include <vector>
//! The base class print is called
//! This is called slicing
//! When a derived class object 
//! is passed by value as 
//! base class object, 
//! the base class 
//! copy constructor is called.
// TODO set this right

class Base {
public:
    int x;

    Base(int x) {
        this->x = x;
    }

    virtual void print() {
        std::cout << "Base::print(): x = " << x << std::endl;
    }
};

class Derived : public Base {
public:
    int y;

    Derived(int x, int y) : Base(x) {
        this->y = y;
    }

    void print() override {
        std::cout << "Derived::print(): x = " << x << ", y = " << y << std::endl;
    }
};

int main() {
    // Create a vector of Base objects
    std::vector<Base> v;

    // Create a Derived object and insert it into the vector
    Derived d(1, 2);
    v.push_back(d);

    // Print the vector
    for (auto& b : v) {
        b.print(); // This will call Base::print() instead of Derived::print()
    }

    return 0;
}
