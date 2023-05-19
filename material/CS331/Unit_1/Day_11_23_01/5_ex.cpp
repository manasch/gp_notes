#include <iostream>
using namespace std;

// ptr_t should support
//	!= ==
//  dereferencing for rvalue
//	pre increment; post increment

// component to which ptr points to should support
//	<< operator
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
#if 0
void myswap(int& a, int& b)
{
	int temp(a); a = b; b = temp;
}
void mysort(int a[], int n)
{
	int i;
	int j;
	for(i = 0; i < n - 1; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if(a[j] < a[i])
			{
				myswap(a[i], a[j]);
			}
		}
	}
}
#endif
template<typename T>
void myswap(T& a, T& b)
{
	T temp(a); a = b; b = temp;
}
template<typename T>
void mysort(T a[], int n)
{
	int i;
	int j;
	for(i = 0; i < n - 1; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if(a[j] < a[i])
			{
				myswap(a[i], a[j]);
			}
		}
	}
}
int main()
{
	int a[] = {20, 50, 30, 40, 10};
	int n = 5;
	disp(a, a + n);
	mysort(a, n);
	disp(a, a + n);
	
	double b[] = {2.0, 5.0, 3.0, 4.0, 1.0};
	int m = 5;
	disp(b, b + m);
	mysort(b, m);
	disp(b, b + m);
}


// p()
// (*p)()

