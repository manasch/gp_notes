#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  T x;
};

template <typename T>
class Middle : public Base<T> {
 public:
  T y;
};

template <typename T>
class Derived : public Middle<int> {
 public:
  T z;
};

int main() {
  Derived<double> d;
  cout << typeid(d.x).name() << endl;
  cout << typeid(d.z).name()<< endl;
  // d.x = 1;  // error: x is of type int, not double
  return 0;
}
/*
#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  T x;
};
template <typename T>
class Middle : public Base<T> {
 public:
  T y;
};

template <typename T>
class Derived : public Middle<T> {
 public:
  T z;
};

int main() {
  Derived<double> d;
  cout << typeid(d.x).name() << typeid(d.y).name() << typeid(d.z).name() ;
  d.x = 1.0;  // now x is of type double
  return 0;
}

*/