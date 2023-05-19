#include <iostream>
using namespace std;

class A
{
	public:
	A() { cout << "ctor\n"; }
	~A() { cout << "dtor\n"; }
	A(const A&) { cout << "copy constructor\n"; }
	A& operator=(const A&) { cout << "copy assignment op\n"; return *this; }
	A(A &&) { cout << "move constructor\n"; }
	A& operator=(A && ) { cout << "move assignment operator\n"; return *this; }
};

int main()
{
#if 0
	{
		A x; // ctor
		A y(x); // copy ctor
		A z; // ctor
		z = x; // copy assignment 
	} // dtor z; dtor y; dtor x
#endif
	{
		A x; // ctor
		A y(move(x)); // move ctor
		y = move(x); // move assign
	}	// dtor y; dtor x
}
