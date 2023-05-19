#include <iostream>
using namespace std;
template<typename ptr_t>
void disp(ptr_t first, ptr_t last)
{
	while(first != last)
	{
		cout << *first << "\t";
		++first;
	}
	cout << "\n";
}
// acc1 : accumulate
#if 0
int acc1(int *first, int *last)
{
	int init = 0;
	while(first != last)
	{
		init += *first;
		++first;
	}
	return init;
}
#endif
// T() : default value of type T
// int() => 0
// double() => 0.0

template<typename T>
T acc1(T *first, T *last)
{
	T init = T();
	while(first != last)
	{
		init += *first;
		++first;
	}
	return init;
}

template<typename T, typename ptr_t>
T acc2(ptr_t first, ptr_t last)
{
	T init = T();
	while(first != last)
	{
		init += *first;
		++first;
	}
	return init;
}

template<typename T, typename ptr_t>
T acc3(ptr_t first, ptr_t last, T init)
{
	while(first != last)
	{
		init += *first;
		++first;
	}
	return init;
}
// binop : int (*)(int, int)
//	cout << "total : " << acc4(a, a + 5, 0, add) << "\n";
//	cout << "total : " << acc4(a, a + 5, 1, mul) << "\n";

template<typename T, typename ptr_t, typename binop_t>
T acc4(ptr_t first, ptr_t last, T init, binop_t op)
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
// Try : find the highest

int main()
{
	int a[] = {3, 5, 1, 4, 2};
	disp(a, a + 5);
	double b[] = {3.3, 5.5, 1.1, 4.4, 2.2};
	disp(b, b + 5);
	
	cout << "total : " << acc1(a, a + 5) << "\n";
	cout << "total : " << acc1(b, b + 5) << "\n";

//	implicit instantiation fails for finding type of T
//	cout << "total : " << acc2(a, a + 5) << "\n";
// explicit instantiation
	cout << "total : " << acc2<int, int*>(a, a + 5) << "\n";
// implicit and explicit
	cout << "total : " << acc2<int>(a, a + 5) << "\n";
	cout << "total : " << acc2<int>(b, b + 5) << "\n";
	
	cout << "total : " << acc3(a, a + 5, 0) << "\n";
	cout << "total : " << acc3(a, a + 5, 20) << "\n";
	
	cout << "total : " << acc4(a, a + 5, 0, add) << "\n";
	cout << "total : " << acc4(a, a + 5, 1, mul) << "\n";
	
	
}
