#include <iostream>

template<typename T>
void assign_values(T& var) {
    std::cin >> var;
}

template<typename T, typename... Args>
void assign_values(T& var, Args&... args) {
    std::cin >> var;
    assign_values(args...);
}

int main() {
    int a;
    double b;
    std::string c;

    assign_values(a, b, c);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    return 0;
}
