#include <iostream>
template<class T>
class Base
{
public:
    void set (const T& val) { data = val; }
private: 
    T data;
};
template<class T>
class Derived : public Base<T>
{
public:
    void set (const T& val);
};

template<class T>
void Derived<T>::set(const T& v)
{
    Base<T>::set(v);
    std::cout << "Additional logic";
}

int main()
{
    Derived<int> d;
    d.set(10);
    return 0;
}
