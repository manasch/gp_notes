// TODO   create a base class 
// TODO   override the base class 
// TODO   print function
#include <iostream>

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

    // TODO overide the print function
};

int main() {
    //TODO Create a Derived object
    

    //TODO Create a Base pointer 

    //TODO and point it to the 
    //TODO Derived object


    //TODO  Call print() on the
    //TODO  Base pointer

//! What does it print - base or derived


    return 0;
}
