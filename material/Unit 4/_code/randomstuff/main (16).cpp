#include<iostream>
template<typename Derived>
class Base {
public:
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};

class Derived : public Base<Derived> {
public:
    void implementation() {
        std::cout << "Justice and Virtue are my birthright, because I know everything"; // [1]
    }
};
int main()
{
Derived d;
d.interface();
}
// Ans [1]
// Compilation error
//  No output
//  Undefined
