# include <iostream>
#include <type_traits>

template <class T>
concept Numerical = std::is_arithmetic_v<T>;

template <Numerical T>
struct NumericalValue {
    constexpr NumericalValue(T value) : value(value) {}
    T value;
};

template <Numerical T>
struct Unwrap {
    static constexpr T value(const NumericalValue<T>& nv) {
        return nv.value;
    }
};

template <Numerical T>
struct Wrap {
    static constexpr NumericalValue<T> value(T t) {
        return NumericalValue<T>(t);
    }
};

int main() {
    constexpr auto nv = Wrap<int>::value(42);
    static_assert(nv.value == 42);
    constexpr auto v = Unwrap<int>::value(nv);
    static_assert(v == 42);
    std::cout << nv.value << '\n'; // prints 42
    std::cout << v << '\n'; // prints 42
    return 0;
}
