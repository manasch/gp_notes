#include <iostream>

template <typename T>
class OuterClass {
 public:
  template <typename U>
  class InnerClass {
   public:
    U data;
  };

  InnerClass<T> inner;

  void setData(T data) { inner.data = data; }
  T getData() { return inner.data; }
};

int main() {
  OuterClass<int> outer;
  outer.setData(5);
  std::cout << "Data in outer class: " << outer.getData() << std::endl;
  return 0;
}
