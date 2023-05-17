#include <iostream>

template<typename T, typename... Args>
auto multiply_values(T first, Args... rest) {
    if constexpr (sizeof...(rest) == 0) {
        return first;
    } else {
        return first * multiply_values(rest...);
    }
}

int main() {
    int result = multiply_values(1, 2, 3, 4, 5);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
