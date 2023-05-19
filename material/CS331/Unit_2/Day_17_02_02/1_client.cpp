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
	Complex c1(2.2, 3.3);
	c1.disp();
	Complex c2(4.4); // Complex c2(4.4, 0.0)
	c2.disp();
	//Complex c3(); // C legacy; fn decl; no parameter; returns an object of Complex by value
	Complex c3{};
	c3.disp();
	
	c3 = c1.add(c2);
	c3.disp();
}

