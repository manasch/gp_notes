#include <iostream>

class C {
public:
  int x;

  C(int val) : x(val) {
    std::cout << "Constructor called" << std::endl;
  }

  C(const C &obj) {
    x = obj.x;
    std::cout << "Copy Constructor called" << std::endl;
  }
};

int main() {
  C c1(10);
  C c2(c1);
  C c3 = c1;

  std::cout << "c2.x = " << c2.x << std::endl;
  std::cout << "c3.x = " << c3.x << std::endl;

  return 0;
}
