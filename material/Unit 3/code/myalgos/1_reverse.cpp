#include <iostream>
using namespace std;
#include <vector>

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

template<typename T>
void myswap(T& x, T& y)
{
	T temp(x); x = y; y = temp;
}

template<typename ptr_t>
void myreverse(ptr_t first, ptr_t last)
{
	while(first != last && first != --last)
	{
		myswap(*first, *last);
		++first;
	}
}

int main()
{
	int a[] = {11, 22, 33, 44, 55, 66, 77};
	disp(begin(a), end(a));
	myreverse(begin(a), end(a));
	disp(begin(a), end(a));
	cout << "\n";
	
	vector<int> v(begin(a), end(a));
	disp(begin(v), end(v));
	myreverse(begin(v), end(v));
	disp(begin(v), end(v));
	cout << "\n";
}
