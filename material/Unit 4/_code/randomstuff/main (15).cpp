#define MACRO(a,b)  do {int a= 10; int b=21;} while(0);
#include<iostream>
int main()
{ 
   int c = 0;
   if (c)
    MACRO(a,b)
   else
    std::cout << "C is telling lies";
}
