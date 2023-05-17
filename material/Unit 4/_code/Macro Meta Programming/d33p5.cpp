// One level of macro indirection is required in order to resolve __COUNTER__,
// and get varname1 instead of varname__COUNTER__.
#define CONCAT(a, b) CONCAT_INNER(a, b)
#define CONCAT_INNER(a, b) a ## b

#define UNIQUE_NAME(base) CONCAT(base, __LINE__)
#include<iostream>
int main() {
  int UNIQUE_NAME(foo) = 123;  // int foo0 = 123;
  std::cout << foo9;           // prints "123"
  std::cout << __LINE__ ;
  int UNIQUE_NAME(foo) = 21;
  std::cout << foo12;  
  
}