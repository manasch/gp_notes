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
class Derived : public Base<int> {
 public:
  Derived(T data) : Base<int>(static_cast<int>(data)) {}
};

int main() {
  Derived<double> d(42.0);
  d.printData();  // Output: 42 (int, not double)
  return 0;
}
