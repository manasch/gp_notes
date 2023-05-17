#include <iostream>
#include <type_traits>

template <typename T>
constexpr auto foo(T val) {
    if constexpr (std::is_integral_v<T>) {
        return "Integral value: " + std::to_string(val);
    }
    else {
        return "Non-integral value";
    }
}

template <>
constexpr auto foo<int>(int val) {
    return "hello";
}

template <>
constexpr auto foo<float>(float val) {
    return "Float value: " ;
}

int main() {
    constexpr int int_val = 42;
    constexpr float float_val = 3.14f;

 auto x = foo<int>(int_val);
 auto y = foo<float>(float_val); 
auto z =  foo<const char*>("Hello, world!") ; 

    return 0;
}
