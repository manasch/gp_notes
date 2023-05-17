#include <iostream>
using namespace std;

class Grandparent {
public:
    void foo() {
        cout << "Grandparent class's foo() function." << endl;
    }
};

class Parent : public Grandparent {
public:
    void bar() {
        cout << "Parent class's bar() function." << endl;
    }
};

class Derived : public Parent {
public:
    void baz() {
        Grandparent::foo(); // Call the grandparent class's foo() function
        Parent::bar(); // Call the parent class's bar() function
        cout << "Derived class's baz() function." << endl;
    }
};

int main() {
    Derived d;
    d.baz();
    return 0;
}
