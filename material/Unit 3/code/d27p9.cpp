#include <type_traits>
#include <iostream>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_binary(T value)
{
    std::cout << "Binary representation of " << value << " is ";
    for (int i = sizeof(T) * 8 - 1; i >= 0; i--)
        std::cout << ((value >> i) & 1);
    std::cout << std::endl;
}

int main()
{
    int i = 42;
    double d = 3.14159;
    
    print_binary(i);  // OK, int is an integral type
    //!print_binary(d); // Error, double is not an integral type
    
    return 0;
}
