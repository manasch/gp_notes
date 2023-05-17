#include <iostream>

class C {
public:
  int *x;

  C(int val) {
    x = new int;
    *x = val;
    std::cout << "Constructor called" << std::endl;
  }

  // Deep copy constructor
  C(const C &obj) {
    x = new int;
    *x = *obj.x;
    std::cout << "Deep Copy Constructor called" << std::endl;
  }
};

int main() {
  C c1(10);
  C c2(c1);
  C c3 = c1;

  std::cout << "c1.x = " << *c1.x << std::endl;
  std::cout << "c2.x = " << *c2.x << std::endl;
  std::cout << "c3.x = " << *c3.x << std::endl;

  *c1.x = 20;

  std::cout << "After modifying c1.x" << std::endl;

  std::cout << "c1.x = " << *c1.x << std::endl;
  std::cout << "c2.x = " << *c2.x << std::endl;
  std::cout << "c3.x = " << *c3.x << std::endl;

  return 0;
}
