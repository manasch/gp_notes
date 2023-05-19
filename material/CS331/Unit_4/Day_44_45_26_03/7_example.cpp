// Template Meta programming
// non type parameters
#include <iostream>
using namespace std;

// compile time constant
template<int N>
struct What
{
	enum { val = N * N};
};

template<int N>
struct X
{
	enum { val = N };
};
// specialization
template<>
struct X<13>
{
	enum { val = 14 };
};

int main()
{
	cout << What<10>::val << "\n";
	cout << What<20>::val << "\n";
	
	cout << X<10>::val << "\n";
	cout << X<13>::val << "\n";
}
