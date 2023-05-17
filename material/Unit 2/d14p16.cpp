#include <iostream>

class C {
public:
  static int y;

  static void increment() {
    y++;
  }

  static void print() {
    std::cout << "y = " << y << std::endl;
  }
};

int C::y = 0;

int main() {
  C::increment();
  C::increment();
  C::print();

  return 0;
}
