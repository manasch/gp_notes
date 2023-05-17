#include <iostream>
#include <typeinfo>
template<typename T1, typename T2>
class Parent1
{
public:
    T1 p1;
};

template<typename T1, typename T2, typename T3>
class Parent2
{
public:
    T2 p2;
};

template<typename T1, typename T2, typename T3, typename T4>
class Child : public Parent1<T2, T4>, public Parent2<T1, T3, T4>
{
public:
    T3 c1;
    T4 c2;
};

int main()
{
    Child<int, float, char, bool> child;
    std::cout << "child is of type " << typeid(child).name() << std::endl;
    std::cout << "child.p1 is of type " << typeid(child.p1).name() << std::endl;
    std::cout << "child.p2 is of type " << typeid(child.p2).name() << std::endl;
    std::cout << "child.c1 is of type " << typeid(child.c1).name() << std::endl;
    std::cout << "child.c2 is of type " << typeid(child.c2).name() << std::endl;
    return 0;
}
