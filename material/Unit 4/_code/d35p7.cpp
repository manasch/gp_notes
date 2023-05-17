#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base class's destructor." << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived class's destructor." << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // Call the base class destructor
    return 0;
}
