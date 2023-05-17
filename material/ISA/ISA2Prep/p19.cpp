#include <iostream>
class Outer {
public:
  Outer(int val) : value(val) {}
  class Inner {
  public:
    Inner(Outer& o) : outer(o) {}
    void doSomething() {
      std::cout << "Inner::doSomething() with outer value " << outer.value << std::endl;
    }
  private:
    Outer& outer;
  };

private:
  int value;
};
int main() {
  Outer outerObj(42);
  Outer::Inner innerObj(outerObj);
  innerObj.doSomething();
  return 0;
}
