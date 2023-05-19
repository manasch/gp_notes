#include <iostream>
using namespace std;

#include <vector>

template<typename C>
void foo(const C& c)
{
	// copy the first value from c to a variable
	typename C::value_type res = c.front();
	cout << res << "\n";
}

template<typename T>
void bar(T t)
{
	vector<int>::iterator it;
	typename vector<T>::iterator it1;
}

int main()
{
	vector<int> v{11, 22, 33, 44, 55};
	foo(v);
	vector<double> v1{1.1, 2.2, 3.3, 4.4, 5.5};
	foo(v1);
	bar(10);
}

// interpretation of the code
// A::t *x;   multiplication ; A::t is a static member 
//			  x is a defn of variable of type A::t
// c++ designers made this decision:
// A::t *x : multiplication
// typename A::t *x; // dependent type


