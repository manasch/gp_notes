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
    // Create a vector of Base pointers
    std::vector<Base*> v;

    // Create a Derived object and insert its address into the vector
    Derived d(1, 2);
    v.push_back(&d);

    // Print the vector
    for (auto b : v) {
        b->print(); // This will call Derived::print()
    }

    return 0;
}
