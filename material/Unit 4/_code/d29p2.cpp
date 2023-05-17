#include <iostream>

template<int N>
class Factorial {
public:
    enum { value = N * Factorial<N-1>::value };
};

template<>
class Factorial<1> {
public:
    enum { value = 1 };
};

int main() {
    const int fact5 = Factorial<5>::value;
    std::cout << "Factorial of 5 is: " << fact5 << std::endl; // Output: Factorial of 5 is: 120
    return 0;
}
