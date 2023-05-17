#include <iostream>
template <typename T>
class MyClass {
 private:
  T var1;
  T var2;

 public:
  void f(T x) { var1 = x; }
  void g(T y) { var2 = y; }

  void display() {
    std::cout << "var1: " << var1 << std::endl;
    std::cout << "var2: " << var2 << std::endl;
  }
};

int main() {
  MyClass<int>* p = new MyClass<int>();
  p->f(10);
  p->g(20);
  p->display();

  return 0;
}
