#include <iostream>
#include <type_traits>

template <typename T>
constexpr int print_type_info(T value) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Integral type: " << value << std::endl;
    } else if constexpr (std::is_floating_point<T>::value) {
        std::cout << "Floating-point type: " << value << std::endl;
    } else {
        std::cout << "Other type: " << value << std::endl;
    }
    return 0;
}

int main() {
    const int i = 42;
    const double d = 3.14;
    const char* s = "Hello, world!";

    auto x = print_type_info(i);
    auto y = print_type_info(d);
    auto z = print_type_info(s);

    return 0;
}
