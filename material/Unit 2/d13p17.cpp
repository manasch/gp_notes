#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  virtual void foo() { std::cout << "Base" << std::endl; }
};

template <typename T>
class Derived : public Base<T> {
 public:
  virtual void foo() { std::cout << "Derived" << std::endl; }
};

int main() {
  Base<int>* p = new Derived<int>();
  p->foo(); 
  return 0;
}
