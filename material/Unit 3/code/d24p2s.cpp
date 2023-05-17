#include <iostream>
//! print the derived class 
//! now create a vector of base class
//! push derived class objects
//! print the derived class objects
//! in a vector and see what happens

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
    // Create a Derived object
    Derived d(1, 2);

    // Create a Base pointer and point it to the Derived object
    Base* b = &d;

    // Call print() on the Base pointer
    b->print(); // This will call Derived::print()

    return 0;
}
