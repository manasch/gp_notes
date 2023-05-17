#include <iostream>
#include <type_traits>

template <typename T>
struct ReturnType;

template <>
struct ReturnType<int> {
    static constexpr int value = 1;
};

template <>
struct ReturnType<float> {
    static constexpr float value = 2.0f;
};

template <typename T>
constexpr auto someFunction(T value) {
    if constexpr (std::is_same_v<T, int>) {
        return ReturnType<int>::value * value;
    }
    else if constexpr (std::is_same_v<T, float>) {
        return ReturnType<float>::value * value;
    }
}

int main() {
    constexpr int intVal = 5;
    constexpr float floatVal = 3.14f;
    constexpr auto intResult = someFunction(intVal);     // Returns 5
    constexpr auto floatResult = someFunction(floatVal); // Returns 6.28f
    std::cout << intResult << std::endl;
    std::cout << floatResult << std::endl;
    return 0;
}
