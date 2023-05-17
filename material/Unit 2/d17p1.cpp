// !Dependent types are those 
// !whose type(datatype) is dependent on a
// !template parameter. 
#include<iostream>
template<typename T>
class Vector {
public:
  Vector<T> (){ std::cout << "Vector";} 
  //! Dependent
  T *data; // !dependent
  int size; // TODO non-dependent
  Vector(int size) : size(size), data(new T[size]) {}
  ~Vector() { delete[] data; }
};
int main()
{
    Vector<int> v;

}
