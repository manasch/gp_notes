#include <type_traits>
#include <iostream>

template <typename T>
void foo(T val)
{
    if (std::is_integral<T>::value) {
        std::cout << "The value is an integral type.\n";
    } else {
        std::cout << "The value is not an integral type.\n";
    }
}

int main()
{
    int i = 42;
    float f = 3.14f;

    foo(i); //* prints "The value is an integral type."
    foo(f); //* prints "The value is not an integral type."
}
