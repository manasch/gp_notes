#include <iostream>

template <typename T>
class Base{
public:
  void func1() const {
    std::cout << "func1()\n";
  }
  void func2() const {
    std::cout << "func2()\n";
  }
  void func3() const {
    std::cout << "func3()\n";
  }
};

template <typename T>
class Derived: public Base<T>{
public:
  using Base<T>::func2;              // (2)
  void callAllBaseFunctions(){

    this->func1();                   // (1) Make this implicit dependent
    func2();                         // (2) The expression using Base<T>::func2 
    Base<T>::func3();                // (3) Fully qualify

  }
};


int main(){

  std::cout << '\n';

  Derived<int> derived;
  derived.callAllBaseFunctions();

  std::cout << '\n';

}