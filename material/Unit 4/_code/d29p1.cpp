#include <iostream>
//* A constexpr function that computes the nth Fibonacci number
constexpr int fib(int n) {
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

int main() {
    int fib_10 = fib(10); //* evaluated at compile-time
    std::cout << "fib(10) = " << fib_10 << std::endl; // prints "fib(10) = 55"
    
    int n = 10;
    const int fib_n = fib(n); // evaluated at runtime
    std::cout << "fib(" << n << ") = " << fib_n << std::endl;
    return 0;
}
