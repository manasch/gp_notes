#include <iostream>

class NonTemplate
{
 public:
  void setData(int val) { data = val; }
  int getData() { return data; }

 private:
  int data;
};

template <typename T>
class Derived : public NonTemplate
{
 public:
  void set(const T& val) { derived_data = val; }
  T get() { return derived_data; }

 private:
  T derived_data;
};

int main()
{
  Derived<int> d;
  d.setData(5);
  d.set(10);
  std::cout << "Non-template data: " << d.getData() << std::endl;
  std::cout << "Template data: " << d.get() << std::endl;

  return 0;
}
