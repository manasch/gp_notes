#include <iostream>
using namespace std;

// concept of pointers and reference
// pointer:
//		may be initialized
//		has to be dereferenced explicitly
//		pointer can be changed
//		pointer may be grounded

// reference:
//		has to be initialized
//		dereference implicitly
//		reference can never be changed
//		reference can not be grounded


// l value and r value
//	wrt assignment operator
//	'C'
//		only operator which gives a l value back : *
//	C++ :
//		if the result of an operation is in a variable of the programmer and
//			not a temporary, it is a l value
//		a = 10;
//		a++ : result stored in a temporary
//		++a : do we require a temporary? NO; result is in a
//		a++ : r value
//		++a : l value
//		a++++ : syntax error
//		++++a : ok

int main()
{
#if 0
	int a(10);
	int *p(&a);
	int *q; // uninitialized
	
	int r = *p;
	*p = 20;
	
	int b(30);
	p = &b;
	
	p = nullptr; 
#endif

	int a(10);
	int& r(a); // r : reference variable
	// reference is an alias for referent (conceptually)
	
	//int& r1; // compile time error
	int b(r); // int b(a)
	r = 20;  // a = 20

	int c(30);
	r = c; // a = c; // r does not change
	
}

// 'C' : parameter passing mechanism : pass by value
// C++ : pass by value
//		 pass by reference
//
//	change the argument (simple type or structured type)
//		pass by reference

// do not want to change the argument
//		simple type : pass by value
//		structured type : pass by reference to const(trivial conversion)




