#include <iostream>

class C {
public:
  int x;

  C() {
    x = 0;
  }

  void increment() {
    x++;
  }

  void print() {
    std::cout << "x = " << x << std::endl;
  }
};

int main() {
  static C c1;
  c1.increment();
  c1.increment();
  c1.print();

  return 0;
}
