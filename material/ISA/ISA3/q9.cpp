#include <iostream>
#include <type_traits>

template <typename T>
void check_integral(T value) {
    if (std::is_integral<T>::value) {
        std::cout << value << 
        " is an integral type.\n";
    } else {
        std::cout << value << "
         is not an integral type.\n";
    }
}

int main() {
    check_integral(42);
    check_integral(42ul);
    check_integral(42ll);
    check_integral("hello");
    return 0;
}
