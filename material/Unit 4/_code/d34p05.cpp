#include <iostream>
#include <type_traits>

template <int N>
struct Factorial {
    static_assert(N >= 0, "Factorial of a negative number is undefined!");

    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    std::cout << Factorial<0>::value << std::endl; // Output: 1
    std::cout << Factorial<1>::value << std::endl; // Output: 1
    std::cout << Factorial<5>::value << std::endl; // Output: 120
    std::cout << Factorial<10>::value << std::endl; // Output: 3628800
    // std::cout << Factorial<-5>::value << std::endl; // Compile-time error: Factorial of a negative number is undefined!
    return 0;
}
