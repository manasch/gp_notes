/*
// callback : pointer to fn
//			  functor
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
*/

#include <iostream>
using namespace std;

template<typename ptr_t, typename T, typename binop_t>
T acc(ptr_t first, ptr_t last, T init, binop_t op)
{
	while(first != last)
	{
		init = op(init, *first);
		++first;
	}
	return init;
}
int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }

// functor class
struct Add
{
	int operator()(int x, int y) { return x + y; }
};

int main()
{
	int a[] = {3, 1, 5, 2, 4};
	cout << "acc : " << acc(a, a + 5, 0, add ) << "\n";
	cout << "acc : " << acc(a, a + 5, 1, mul ) << "\n";
	cout << "acc : " << acc(a, a + 5, 0, Add() ) << "\n";
	
}




