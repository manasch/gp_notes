#include <iostream>
using namespace std;
#include "1_person.h"

#if 0
// version 1
// aliasing
int main()
{
	char name[]  = "amar";
	Person a(name, 20);
	a.disp();
	name[0] = ' ';
	a.disp(); // name_ of a also got changed
	
}
#endif

#if 1
// version 2
int main()
{
#if 0
	{
		char name[]  = "amar";
		Person a(name, 20);
		a.disp();
		name[0] = ' ';
		a.disp(); 
	}
	{
	// require a default ctor
	//	1) ctor with no parameters
	//	2) make all parameters have default values
		Person b;
		b.disp();
	}
#endif
#if 0
	{
		Person x("amar", 20);
		Person y("beena", 18);
		// by default :
		//	shallow copy or memberwise copy
		y = x; // y.operator=(x)// Person::operator=(&y, x);
		x.disp();
		y.disp();
	}
#endif
#if 0
// self assignment
	{
		Person x("amar", 20);
		x.disp();
		x = x;
		x.disp();
	}
#endif
#if 1
	{
		Person x("amar", 20);
		Person y("beena", 18);
		Person z("chandra", 16);
		
		x = y = z;
	}
#endif
#if 0
	{
		Person x("amar", 20);
		Person y(x); // copy constructor  Person y = x;
	}
#endif
}
// int a; double b = 2.8; double c;
// c = a = b
/*
struct XXX
{
	int a;
	int b[4];
};
struct XXX x1;

*/

#endif

