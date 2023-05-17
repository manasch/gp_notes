#include<iostream>
template <typename T1, typename T2>
class Grandfather {
 public:
  Grandfather(const T1& a, const T2& b) : x(a), y(b) {}
  void print() const {
    std::cout << "Grandfather: x = " << x << ", y = " << y << std::endl;
  }

 private:
  T1 x;
  T2 y;
};

template <typename T1, typename T2, typename T3>
class Parent : public Grandfather<T1, T2> {
 public:
  Parent(const T1& a, const T2& b, const T3& c)
      : Grandfather<T1, T2>(a, b), z(c) {}
  void print() const {
    Grandfather<T1, T2>::print();
    std::cout << "Parent: z = " << z << std::endl;
  }

 private:
  T3 z;
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Parent<T1, T2, T3> {
 public:
  Child(const T1& a, const T2& b, const T3& c, const T4& d)
      : Parent<T1, T2, T3>(a, b, c), w(d) {}
  void print() const {
    Parent<T1, T2, T3>::print();
    std::cout << "Child: w = " << w << std::endl;
  }

 private:
  T4 w;
};

int main() {
  Child<int, double, char, std::string> c(1, 2.3, 'a', "Hello");
  c.print();
  return 0;
}
