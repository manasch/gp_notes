// ctor and dtor calls
#include <iostream>
using namespace std;

class A
{
	public:
	A();
	~A();
};
// size : instance variable and not on functions
//		of an empty class : one byte 
//		FAQ : Stroustrup

A::A()
{
	cout << "ctor\n";
}
A::~A()
{
	cout << "dtor : " << this << "\n";
}

int main()
{
#if 0
	cout << "one\n";
	{
		cout << "two\n";
		A x; // ctor
		cout << "three\n";
	} // dtor
	cout << "four\n";
#endif

#if 0
	cout << "one\n";
	{
		cout << "two\n";
		A x[4]; // ctor 4 times
		cout << "three\n";
	} // dtor 4 times
	cout << "four\n";
#endif
#if 0
	cout << "one\n";
	{
		cout << "two\n";
		{
			A x; // ctor  
			{
				cout << "----\n";
				A& r(x); // no ctor
				cout << "----\n";
			} // no dtor
		} // dtor
		cout << "three\n";
	}	  
	cout << "four\n";
#endif

#if 0
	cout << "one\n";
	{
		cout << "two\n";
		A *p;  // no ctor
		{
			p = new A; // ctor
			delete p; // dtor
		}
		cout << "three\n";
	}  // no dtor
	cout << "four\n";
#endif
#if 1
	cout << "one\n";
	{
		cout << "two\n";
		A *p;  // no ctor
		{
			p = new A[4]; // ctor 4 times
			//delete p; // undefined behaviour
			delete [] p;
		}
		cout << "three\n";
	}  // no dtor
	cout << "four\n";
#endif
}



