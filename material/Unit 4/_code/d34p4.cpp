#include <iostream>
#include <type_traits>

template <class T>
concept Numerical = std::is_arithmetic_v<T>;

template <Numerical T>
struct NumericalValue {
    T value;
};

template <Numerical T>
NumericalValue<T> wrap(T value) {
    return { value };
}

template <Numerical T>
T unwrap(NumericalValue<T> t) {
    return t.value;
}

int main() {
    auto nv = wrap(42);
    std::cout << nv.value << '\n'; // prints 42
    auto v = unwrap(nv);
    std::cout << v << '\n'; // prints 42
}
