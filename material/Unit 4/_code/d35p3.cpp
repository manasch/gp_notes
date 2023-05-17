#include <iostream>
using namespace std;

class Base {
public:
    virtual void foo() {
        cout << "Base class's foo() function." << endl;
    }
};

class Derived : public Base {
public:
    void foo() override {
        Base::foo(); // Call the base class's foo() function
        cout << "Derived class's foo() function." << endl;
    }
};

int main() {
    Derived d;
    d.foo();
    return 0;
}
