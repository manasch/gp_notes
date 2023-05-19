#include <iostream>
using namespace std;

#if 0
int foo(int (*f)(int), int n)
{
	return f(n);
}
#endif
template<typename unary_op_t, typename T>
T foo(unary_op_t f, T n)
{
	return f(n);
}
class SqSq
{
	public:
	int operator()(int x) { return x * x * x * x; }
};

int sq(int x) { return x * x; }
int cube(int x) { return x * x * x; }
int main()
{
	cout << foo(sq, 10) << "\n";
	cout << foo(cube, 10) << "\n";
	
	cout << foo(SqSq(), 10) << "\n";
}



