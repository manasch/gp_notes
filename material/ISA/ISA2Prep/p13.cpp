#include <iostream>

template<typename X>
class Base {
public:
    int basefield;
    using T = float;
};

class D1: public Base<Base<void>> {
public:
    void f() { basefield = 3; }
};

template<typename U>
class D2 : public Base<double> {
public:
    void f() { basefield = 7; }
    U strange;
};

int main()
{
    D2<int> d2;
    d2.f();
    std::cout << "strange in D2 is of type " << typeid(d2.strange).name() << std::endl;
    return 0;
}
