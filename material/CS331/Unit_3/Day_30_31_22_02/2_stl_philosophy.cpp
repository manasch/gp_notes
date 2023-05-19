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
	int a[] = {33, 11, 22, 55, 44};
	vector<int> v(5);
	// copy from one container to another
	// copy: destination should have memory
	copy(a, a + 5, v.begin());
	disp(v.begin(), v.end());
	
	deque<int> d(5);
	copy(begin(v), end(v), begin(d));
	disp(d.begin(), d.end());
	
	list<int> l(5);
	copy(begin(a), end(a), begin(l));
	disp(l.begin(), l.end());
	
}
// begin(v) : wrapper => calls v.begin()

