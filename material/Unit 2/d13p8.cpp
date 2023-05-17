#include <iostream>

template <typename T>
class Base {
 public:
  void set(const T& val) { data = val; }

  T get() const { return data; }

 private:
  T data;
};

template <typename U>
class Derived : public Base<int> {
 public:
  void setDerived(const U& val) { derived_data = val; }

  U getDerived() const { return derived_data; }

  int getBase() const { return Base<int>::get(); }

  void setBase(const int& val) { Base<int>::set(val); }

 private:
  U derived_data;
};

int main() {
  Derived<std::string> d;
  d.setBase(3);
  d.setDerived("Hello World");

  std::cout << "Base data: " << d.getBase() << std::endl;
  std::cout << "Derived data: " << d.getDerived() << std::endl;

  return 0;
}
