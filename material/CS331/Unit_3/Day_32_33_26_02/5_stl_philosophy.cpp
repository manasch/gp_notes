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

// 4. reverse

// 5. sort

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
	// sort
	int a[] = {22, 77, 55, 11, 44, 33, 66};
	vector<int> v(begin(a), end(a));
	deque<int> d(begin(a), end(a));
	list<int> l(begin(a), end(a));

	disp(begin(a), end(a));
	sort(begin(a), end(a));
	disp(begin(a), end(a));
	cout << "\n";
	
	disp(begin(v), end(v));
	sort(begin(v), end(v));
	disp(begin(v), end(v));
	cout << "\n";
	
	
	disp(begin(d), end(d));
	sort(begin(d), end(d));
	disp(begin(d), end(d));
	cout << "\n";
	
#if 0
	disp(begin(l), end(l));
	// sort algo does not work on list
	sort(begin(l), end(l));
	disp(begin(l), end(l));
	cout << "\n";
#endif
	disp(begin(l), end(l));
	l.sort();
	disp(begin(l), end(l));
	cout << "\n";
}
