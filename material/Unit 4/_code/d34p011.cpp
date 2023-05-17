#include <iostream>

constexpr int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    constexpr int x = 5;
    constexpr int y = 120; // factorial of 5 is 120
    constexpr int z = 720; // factorial of 6 is 720

    constexpr int fact = factorial(x);

    switch (fact) {
        case y:
            std::cout << "Factorial of " << x << " is " << y << std::endl;
            break;
        case z:
            std::cout << "Factorial of " << (x + 1) << " is " << z << std::endl;
            break;
        default:
            std::cout << "Factorial of " << x << " is not " << y << " or " << z << std::endl;
            break;
    }
    return 0;
}