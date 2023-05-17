/*
A friend template can declare only primary
 templates and members of primary templates. 
 Any partial specializations and 
explicit specializations associated 
with a primary template are automatically 
considered friends too
*/
#include<iostream>
using namespace std;

template<typename T>
class B {
public:
  void foo() {
    std::cout << "Primary Template\n";
  }
};

// Explicit specialization for T = int
template<>
class B<int> {
public:
  void foo() {
    std::cout << "Explicit Specialization for T = int\n";
  }
} ;

// Partial specialization for T = T*
template<typename T>
class B<T*> {
public:
  void foo() {
    std::cout << "Partial Specialization for T = T*\n";
  }
};

template<typename T>
class A {
private:
  T m_val;

public:
  A(T val) : m_val(val) {}
  friend class B<T>;
};

int main() {
  A<int> a1(10);
  B<int> b1;
  b1.foo();

  double d = 3.14;
  A<double> a2(d);
  B<double> b2;
  b2.foo();

  A<std::string> a3("hello");
  B<std::string> b3;
  b3.foo();

  return 0;
}
