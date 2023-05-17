#include<iostream>
using namespace std;

template <typename T>
struct printer;

template <typename T>
struct wrapper
{
    wrapper(T const v) :value(v) {}
private:
    T value;
    template <typename U>
    friend void print(wrapper<U> const&);
    template <typename U>
    friend struct printer;
};

template <typename T>
void print(wrapper<T> const& w)
{
    std::cout <<"General" << w.value << '\n';
}

template<>
void print<int>(wrapper<int> const& w)
{
    std::cout <<"Specialization" << w.value << '\n';
}

template <typename T>
struct printer
{
    void operator()(wrapper<T> const& w)
    {
        std::cout << w.value << '\n';
    }
};

template<>
struct printer<int>
{
    void operator()(wrapper<int> const& w)
    {
        std::cout << w.value << '\n';
    }
};

int main()
{
    wrapper<int> w(42);
    print<int>(w);
    printer<int>()(w);
}
