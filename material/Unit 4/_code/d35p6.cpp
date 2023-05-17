#include <iostream>
using namespace std;

class Base {
public:
    virtual void foo() {
        cout << "Base class's foo() function." << endl;
    }
};

class Derived1 : public Base {
public:
    void foo() override {
        cout << "Derived1 class's foo() function." << endl;
    }
};

class Derived2 : public Base {
public:
    void foo() override {
        cout << "Derived2 class's foo() function." << endl;
    }
};

int main() {
    Base* ptr = nullptr;
    int a = 1;
    if (a == 1) {
        ptr = new Derived1();
    } else {
        ptr = new Derived2();
    }
    ptr->foo(); // Call the virtual function based on the actual object type
    delete ptr;
    return 0;
}
