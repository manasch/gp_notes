// cppinsights.io
// Dependent types are those 
// whose type is dependent on a template parameter. 
#include<iostream>
template<typename T>
class Vector
{
  
  public: 
  inline Vector()
  {
    std::operator<<(std::cout, "Vector");
  }
  
  T * data;
  int size;
  inline Vector(int size)
  : size{size}
  , data{new T[static_cast<unsigned long>(size)]}
  {
  }
  
  inline ~Vector()
  {
    delete[] this->data;
  }
  
};

/* First instantiated from: insights.cpp:15 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class Vector<int>
{
  
  public: 
  inline Vector()
  {
    std::operator<<(std::cout, "Vector");
  }
  
  int * data;
  int size;
  inline Vector(int size);
  
  inline ~Vector() noexcept
  {
    delete[] this->data;
  }
  
};

#endif

int main()
{
  Vector<int> v = Vector<int>();
  return 0;
}

