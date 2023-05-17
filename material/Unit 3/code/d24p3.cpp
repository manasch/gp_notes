#include <iostream>
#include <vector>
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
    // TODO  Create a vector of Base objects
    

    //TODO  Create a Derived object 
     
    // TODO push_back the derived obejct 
    // TODO vector


    // TODO  Print the vector
    // *for (auto& b : v) {
    // *    b.print(); 
    // * }

    //! What got printed

    return 0;
}
