#include <iostream>
int square(int x) {
  return x * x;
}
class AddTwo {
public:
  int operator()(int x) {
    return x + 2;
  }
};
template <typename T, T (*Func)(T) = square, class C = AddTwo>
class MyTemplateClass {
public:
  T getValue(T value) {
    C obj;
    return Func(obj(value));
  }
};

int main() {
  MyTemplateClass<int> myObject;
  int result = myObject.getValue(5); // This calls AddTwo::operator()(5) and then square(7)
  std::cout << result << std::endl;  // Output: 49
  MyTemplateClass<int, square> myObject2;
  int result2 = myObject2.getValue(5); // This calls square(5)
  std::cout << result2 << std::endl;  // Output: 25
  return 0;
}
