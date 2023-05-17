#include<iostream>
template<typename... Args>
struct Count;

template<typename T, typename... Args>
struct Count<T, Args...> {
    static constexpr std::size_t value = 1 + Count<Args...>::value;
};

template<>
struct Count<> {
    static constexpr std::size_t value = 0;
};

int main() {
    constexpr std::size_t count = Count<int, double, char,float>::value;
    std::cout << count << std::endl;
}
