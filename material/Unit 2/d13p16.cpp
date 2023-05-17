#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  T data;
};

template <typename T>
class Derived : public Base<T> {
 public:
  T GetData() { return Base<T>::data; 
      //return T data ;
  }  
};
int main() {
  Derived<int> d;
  d.data = 100;
  std::cout << d.GetData() << std::endl;
  return 0;
}

