#include<iostream>
struct B1{

 constexpr  B1(int a) { mem = a;}
 int mem;
};
int main()
{
  constexpr  B1 b(10);
}