#include <type_traits>
#include <iostream>

template<typename T>
constexpr std::enable_if_t<std::is_integral_v<T>, T>
increment(T value) {
    const int  tmp = 2;
    return ++value+tmp;
}

template<typename T>
constexpr std::enable_if_t<std::is_floating_point_v<T>, T>
increment(T value) {
    return ++value;
}

int main() {
    constexpr int i = increment(1);
    constexpr float f = increment(2.0f);
    std::cout << "i: " << i << std::endl;
    std::cout << "f: " << f << std::endl;
    return 0;
}
