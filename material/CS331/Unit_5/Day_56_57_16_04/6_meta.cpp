#include <iostream>
using namespace std;

struct two
{
    char c[2];
};

template <class T> char test(int T::*);

template <class T> two test(...);

class X
{
};

template <typename T> struct is_a_class
{
    const static bool value = sizeof(test<T>(0)) == 1;
};
int main()
{
    int a;
    cout << sizeof(test<X>(0)) << "\n";
    cout << sizeof(test<int>()) << "\n";
    cout << is_a_class<X>::value << "\n";
    cout << is_a_class<int>::value << "\n";
}
