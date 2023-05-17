#include <iostream>

template<typename Derived>
class Base {
public:
  void foo() {
    static_cast<Derived*>(this)->fooImpl();
  }
};

class DerivedA : public Base<DerivedA> {
public:
  void fooImpl() {
    std::cout << "DerivedA::fooImpl() called" << std::endl;
  }
};

class DerivedB : public Base<DerivedB> {
public:
  void fooImpl() {
    std::cout << "DerivedB::fooImpl() called" << std::endl;
  }
};

int main() {
  DerivedA a;
  DerivedB b;

  a.foo();  // prints "DerivedA::fooImpl() called"
  b.foo();  // prints "DerivedB::fooImpl() called"

  return 0;
}
