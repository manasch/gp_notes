#include <iostream>
using namespace std;
#include "date.h"
template<typename ptr_t>
void disp(ptr_t first, ptr_t last)
{
	while(first != last)
	{
		cout << *first << "\n";
		++first;
	}
	cout << "\n";
}

// 1. convert Date to a type on which comparison is defined
// 2. specialize this function
#if 0
template<typename T>
bool eq(T x, T y)
{
	return x == y;
}
template<>
bool eq<Date>(Date x, Date y)
{
	// not working because of access control
	return x.dd_ == y.dd_ && x.mm_ == y.mm_ && x.yy_ == y.yy_;
}
#endif
// 3. support the required operation in that class
template<typename T>
bool eq(T x, T y)
{
	return x == y;
}
template<typename T>
void myswap(T& x, T& y)
{
	T temp(x); x = y; y = temp;
}

template<typename T>
void mysort(T x[], int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if(x[j] < x[i])
			{
				myswap(x[i], x[j]);
			}
		}
	}
}

int main()
{
#if 0
	cout << boolalpha;
	cout << eq(10, 10) << "\n";
	
	Date d1(15, 8, 1947);
	Date d2(15, 9, 1947);
	cout << eq(d1, d2) << "\n";
#endif
	Date d[] = { 
			{11, 9, 2001}, 
			{26, 1, 2001},
			{11, 1, 1966},
			{30, 1, 1948},
			{26, 12, 2004}
	};
	disp(d, d + 5);
	mysort(d, 5);
	cout << "\n\n";
	disp(d, d + 5);
}







