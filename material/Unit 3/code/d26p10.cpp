#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    double y = 2.5;

    // Oops, we meant to use add(x, x)
    int result = add(x, y);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
