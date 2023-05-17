#include <iostream>

constexpr int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n-1);
}

int main() {
    constexpr int result = factorial(5);
    std::cout << result << std::endl;
    return 0;
}
