#define n 17
#define p 10+10
#include<iostream>
int main()
{
 std::cout << n << '\n';
 //int n = 3;
std ::cout <<  p*p << std::endl;// you expect (10+10)*(10+10)
#undef p
//* The correct way to do it is 
 #define p (10+10)
 std::cout <<  (p)*(p) << std::endl; // who is going to remember these parenthesis

//* We can define macros which take an 
//*'argument"
//* Remember this is quite 
//*literally string replacement

 #define sq(x) ((x)*(x))

 std::cout <<  sq(3.14) << std::endl;

//*  You can virtually have any operator
 #define cal(op,x) ((x) op (x))
//TODO define a small cal to do this
 std::cout <<  cal(*,10) <<'\t' << cal(+,10);
//TODO make sure that is does not compile 
//TODO in anything other than *,+ using 
//TODO macros
#undef cal
#define cal(op,x) \
do { \
  static_assert(op == '*' || op == '+', "Invalid operator!"); \
  ((op == '*') ? ((x) * (x)) : ((x) + (x))); \
} while (0)
#include<stdio.h>

  int a = 5, b = 2;
  printf("a = %d, b = %d\n", a, b);

  // Example usage of the cal macro
  cal('*', a);
  printf("a * a = %d\n", a);

  cal('+', b);
  printf("b + b = %d\n", b);

  // Trying to use an invalid operator should trigger a static_assert error
  // cal('-', a);  // This will cause a compile-time error

  return 0;
}


}


