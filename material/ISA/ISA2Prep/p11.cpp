#include <iostream>

template <typename T1>
class Parent1
{
public:
    void bar()
    {
        std::cout << "Parent1 bar()" << std::endl;
    }
};

template <typename T2>
class Parent2
{
public:
    void bar()
    {
        std::cout << "Parent2 bar()" << std::endl;
    }
};

template <typename T1, typename T2>
class Child : public Parent1<T1>, public Parent2<T2>
{
public:
    void bar()
    {
        Parent1<T1>::bar();
        Parent2<T2>::bar();
        std::cout << " I am my parents and more";
    }
};

int main()
{
    Child<int, float> child;
    child.bar();
    return 0;
}
