#include <iostream>
using namespace std;
#include "1_complex.h"

int foo()
{
	int x = 10;
	return x;
}
int bar()
{
	return 10;
}
// return object optimization

int main()
{
#if 0
	Complex c1(2.2, 3.3);
	c1.disp();
	Complex c2(4.4); // Complex c2(4.4, 0.0)
	c2.disp();
	//Complex c3(); // C legacy; fn decl; no parameter; returns an object of Complex by value
	Complex c3{};
	c3.disp();
	
	c3 = c1.add(c2);
	c3.disp();
#endif
	Complex c1(2.2, 3.3);
	Complex c2(4.4);
	Complex c3{};
	// 	Complex operator+(const Complex& rhs) const; // *this : const

	c3 = c1 + c2; // c1.operator+(c2);
	c3.disp();
	
	// single argument ctor
	c3 = c1 + 4.0; // c1.operator+(4.0)  c1.operator+(Complex(4.0)) 
	c3.disp();
	
	c3 = 4.0 + c1; // NO
	

}
// operator functions:
// 		- syntactic sugar - still a function call
//		=> 3 + 4 => 12 ? not possible
//		- operators only on user defined type
//		- at least one operand should be of user defined type
//		- C : college; S : student :  student joins the college c + s ?
//		- NO. operator should be meaningful in the domain - never invent operators
//		- Num n(...);  n ** 3 // cube n
//			NO. cannot invent operators
//			only a few C++ operators can be overloaded
//		=> c1 + c2 * c3
//			precedence as in C++
//			c1.operator+(c2.operator*(c3))	Yes
//			(c1.operator+(c2)).operator*(c3) No
//		=> c1 - c2 - c3
//			associativity as in C++
//			c1.operator-(c2.operator-(c3))	No
//			(c1.operator-(c2)).operator-(c3) Yes
//		=> c1 ++ c2
//			rank or arity as in C++
//			error
//		=> arity of * : 1 or 2
//			        &
//					-
//					+
//			can overload for both arities
//		=> arity of () : function call operator
//			how many arguments can a function take?
//			can overload () for any arity



