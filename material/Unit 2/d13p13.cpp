#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  T data;
  Base(T data) : data(data) {}

  void printData() {
    std::cout << data << std::endl;
  }
};

template <typename T>
class Derived : public Base<T> {
 public:
  T data;
  Derived(T data, T baseData) : Base<T>(baseData), data(data) {}

  void printData() {
    std::cout << data << std::endl;
  }
};

int main() {
  Derived<int> d(42, 101);
  d.printData();  // Output: 42
  return 0;
}
