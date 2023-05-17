#include <iostream>
#include <vector>
template<class T>
class Base {
public:
  void setData(const T& val) { data = val; }
  T getData() const { return data; }
private:
  T data;
};

template<class T, class U, class V>
class Derived : public Base<T> {
public:
  void setDerivedData(const U& val) { derived_data = val; }
  U getDerivedData() const { return derived_data; }
  void setVectorData(const std::vector<V>& val) { vector_data = val; }
  std::vector<V> getVectorData() const { return vector_data; }

private:
  U derived_data;
  std::vector<V> vector_data;
};

int main() {
  // create an object of type Derived<int, double, char>
  Derived<int, double, char> d;
  d.setData(10);
  d.setDerivedData(3.14);
  std::vector<char> v = {'a', 'b', 'c'};
  d.setVectorData(v);

  // access the data members of the object
  std::cout << "Base data: " << d.getData() << std::endl;
  std::cout << "Derived data: " << d.getDerivedData() << std::endl;
  std::cout << "Vector data: ";
  for (const auto& c : d.getVectorData()) {
    std::cout << c << " ";
  }
  std::cout << std::endl;

  return 0;
}
