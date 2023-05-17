#include <iostream>
#include <type_traits>

template <typename T,
          typename = typename std::enable_if_t<std::is_arithmetic_v<T>, T>>
struct NumericalValue {
  T value;
};

template <typename T>
NumericalValue<T> wrap(T value) {
  return {value};
}

template <typename T>
T unwrap(NumericalValue<T> num) {
  return num.value;
}

int main() {
  NumericalValue<int> num1 = wrap(42);
  NumericalValue<double> num2 = wrap(3.14159);

  std::cout << "num1 = " << unwrap(num1) << std::endl;
  std::cout << "num2 = " << unwrap(num2) << std::endl;

  // This won't compile because std::string is not an arithmetic type.
  // NumericalValue<std::string> str = wrap("hello");
}
