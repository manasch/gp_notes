#include <iostream>
#include <type_traits>

void algorithm_signed(int i) {
    std::cout << "Signed algorithm called with " << i << std::endl;
}

void algorithm_unsigned(unsigned u) {
    std::cout << "Unsigned algorithm called with " << u << std::endl;
}

template <typename T>
void algorithm(T t) {
    if constexpr (std::is_signed<T>::value) {
        algorithm_signed(t);
    } else if constexpr (std::is_unsigned<T>::value) {
        algorithm_unsigned(t);
    } else {
        static_assert(std::is_signed<T>::value || std::is_unsigned<T>::value, "Must be signed or unsigned!");
    }
}

int main() {
    int i = -42;
    unsigned u = 42;

    algorithm(i);
    algorithm(u);

    // This will cause a static assertion failure at compile-time:
    //algorithm("hello");

    return 0;
}
