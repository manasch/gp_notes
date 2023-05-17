/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<iostream>
using namespace std;
template<typename T>
class C {
public:
    void f();
}; 
template<typename T>
void C<T>::f() 
{
    int i = 21;
  	cout << "Ganesha's number is" << i;
}
void g(void (*x)())
{
  x();
}
void wrapper_f() {
  C<int> c;
  c.f();
}
int main() { 
  g(wrapper_f);
} 


