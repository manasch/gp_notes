#include<iostream>
template<class T> 
class Base
{
public:
  void set (const T& val) { data = val; }
  void get() { std::cout << " data is " << data;}
private: 
  T data;
};

template<class T>
class Derived : public Base<T>
{
public:
  void set (const T& val);
};

template<class T>
void Derived<T>::set(const T& v)
{
  Base<T>::set(v);
}

int main()
{
  Derived<int> d;
  d.set(10);
  d.get();
  return 0;
}
