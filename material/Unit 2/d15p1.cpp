#include<iostream>
using namespace std;
/* No rocket science here a class can be a 
friend of another class and access its 
private members*/
template<typename T>
class Accessor;

template<typename T>
class Container {
  private:
    T data;
    friend class Accessor<T>;
  public:
    Container(T data) : data(data) {}
    //friend class Accessor<T>;
};

template<typename T>
class Accessor {
  public:
    static T getData(const Container<T> &c) {
      return c.data;
    }
};

int main() {
  Container<int> c(10);
  std::cout << Accessor<int>::getData(c) << std::endl;
  return 0;
}
