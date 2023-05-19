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
	Date d1(15, 8, 1947);
	cout << d1 << "\n";
	
	int a[] = {22, 11, 44, 55, 33};
	disp(a, a + 5);
	
	
	Date d[] = { 
			{11, 9, 2001}, 
			{26, 1, 2001},
			{11, 1, 1966},
			{30, 1, 1948},
			{26, 12, 2004},
			{20}
	};
	disp(d, d + 6);
	
}

