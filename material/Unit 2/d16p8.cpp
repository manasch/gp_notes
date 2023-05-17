#include <iostream>
template <typename T>
class Outer {
  private:
    T data;

    template <typename U>
    class Inner {
      private:
        U value;
      public:
        Inner(U v) : value(v) {}
        U getValue() const { return value; }
    };

  private:
    Inner<T> inner;
  public:
    Outer(const T &d, const T &v) : data(d), inner(v) {}
    T getData() const { return data; }
    T getInnerValue() const { return inner.getValue(); }
};

int main() {
  int outerVal = 5;
  int innerVal = 10;
  Outer<int> o(outerVal, innerVal);
  std::cout << o.getData() << std::endl;
  std::cout << o.getInnerValue() << std::endl;
  return 0;
}
