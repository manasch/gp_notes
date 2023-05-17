#include <iostream>

template <typename T>
class MyClass {
 private:
  static T instance;

 public:
  static T& getInstance() {
    return instance;
  }
};

template <typename T>
T MyClass<T>::instance;

int main() {
  MyClass<int> myClass1;
  int& x1 = myClass1.getInstance();
  x1 = 10;
  std::cout << "x1: " << x1 << std::endl;

  MyClass<int> myClass2;
  int& x2 = myClass2.getInstance();
  std::cout << "x2: " << x2 << std::endl;

  std::cout << "x1 and x2 are the same: " << (&x1 == &x2) << std::endl;

  return 0;
}
