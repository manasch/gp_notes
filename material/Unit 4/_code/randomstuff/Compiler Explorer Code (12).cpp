#include<iostream>
template<typename... Args>
constexpr auto sum(Args... args) {
    return (... + args);
}

int main() {
    constexpr int result = sum(1, 2, 3, 4, 5);
    std::cout << result << std::endl;
}
