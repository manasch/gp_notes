#include<iostream>
using namespace std;
template <typename T>
class Outer {
  private:
    T data; // Template value here 

    class Inner {
      private:
        int value;
      public:
        Inner(int v) : value(v) {}
        int getValue() const { return value; }
    };

  private:
    Inner inner;
  public:
    Outer( T d, int v) : data(d), inner(v) {}
    T getData()  { return data; }
    int getInnerValue()  { return inner.getValue(); }
};

int main() {
  Outer<std::string> o("hello", 10);
  std::cout << o.getData() << std::endl;
  std::cout << o.getInnerValue() << std::endl;
  return 0;
}
