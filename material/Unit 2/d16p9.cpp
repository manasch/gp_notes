#include <iostream>
// The outer class has 2 parameters , one which takes
// for itself and the other it uses for inner class

template <typename T, typename U>
class Outer {
  private:
    T data; // self uses

    class Inner {
      private:
        U value; // used by the inner class
      public:
        Inner(U v) : value(v) {}
        U getValue() const { return value; }
    };

  private:
    Inner inner;
  public:
    Outer(T d, U v) : data(d), inner(v) {}
    T getData() { return data; }
    U getInnerValue() { return inner.getValue(); }
};

int main() {
  double outerVal = 5.5;
  int innerVal = 10;
  Outer<double, int> o(outerVal, innerVal);
  std::cout << o.getData() << std::endl;
  std::cout << o.getInnerValue() << std::endl;
  return 0;
}
