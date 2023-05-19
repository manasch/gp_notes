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
int main()
{
#if 0
	Date d1(15, 8, 1947);
	Date d2(d1);
	Date d3;
	
	d3 = d1++; // post incr ; use and change
	// d1.operator++(1)
	cout << "d1 : " << d1 << "\n";
	cout << "d3 : " << d3 << "\n";
	
	d3 = ++d2; // pre incr ; change and use
	// d2.operator++()
	cout << "d2 : " << d2 << "\n";
	cout << "d3 : " << d3 << "\n";
	
	int d = d1; // int d = (int)d1;  =>  int d = d1.operator int();
	cout << d << "\n";
#endif
	
	Date d1(15, 8, 1947);
	Date d2(16, 8, 1947);
	cout << boolalpha;
	cout << (d1 < d2) << "\n";
	cout << (d2 < d1) << "\n";
	cout << (d1 < d1) << "\n";

	
}

