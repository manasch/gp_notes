// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;
  
void print()
{
    cout << "I am empty function and "
            "I am called at last.\n" ;
}
  

template <typename T, typename... Types>
void print(T var1, Types... var2)
{
    cout << var1 << endl ;
  
    print(var2...) ;
}
  
// Driver code
int main()
{
    print(1, 2, 3.14, "Pass me any "
              "number of arguments", 
                  "I will print\n");
  
    return 0;
}
