//strange behavior
#include<iostream>
using namespace std;
template <typename T>
class Base {};

template <>
class Base<int> {
 public:
  int data;
  Base(int data) : data(data) {}
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
  d.printData(); //42
  d.Base<int>::printData();  // Output: 101
  return 0;
}


