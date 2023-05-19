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
}


#endif

