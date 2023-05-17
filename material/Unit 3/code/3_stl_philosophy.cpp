#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

// algorithm : 
//	free functions
//	not part of the class
//	efficiency : expressed in amortized way

// 1. find :
//		returns the position if element is found : valid iterator
//		returns an iterator not in the valid range if element is not found

// 2. copy

// 3. replace

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
int main()
{
	// replace elements with a given value by another
	int a[] = {11, 100, 22, 100, 33, 100, 44};
	disp(begin(a), end(a));
	replace(begin(a), end(a), 100, 200);
	disp(begin(a), end(a));
	cout << "\n";
	
	vector<int> v(begin(a), end(a));
	disp(begin(v), end(v));
	replace(begin(v), end(v), 200, 300);
	disp(begin(v), end(v));
	cout << "\n";
	
	deque<int> d(begin(a), end(a));
	disp(begin(d), end(d));
	replace(begin(d), end(d), 200, 400);
	disp(begin(d), end(d));
	cout << "\n";
	
	list<int> l(begin(a), end(a));
	disp(begin(l), end(l));
	replace(begin(l), end(l), 200, 400);
	disp(begin(l), end(l));
	cout << "\n";


}


