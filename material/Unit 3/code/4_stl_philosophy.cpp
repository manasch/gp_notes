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
	// reverse
	int a[] = {11, 22, 33, 44, 55, 66, 77};
	disp(begin(a), end(a));
	reverse(begin(a), end(a));
	disp(begin(a), end(a));
	cout << "\n";
	
	vector<int> v(begin(a), end(a));
	disp(begin(v), end(v));
	reverse(begin(v), end(v));
	disp(begin(v), end(v));
	cout << "\n";
	
	deque<int> d(begin(a), end(a));
	disp(begin(d), end(d));
	reverse(begin(d), end(d));
	disp(begin(d), end(d));
	cout << "\n";
	
	list<int> l(begin(a), end(a));
	disp(begin(l), end(l));
	reverse(begin(l), end(l));
	disp(begin(l), end(l));
	cout << "\n";


}
//    1 2 3 4 5 6 7 8 9 10
//		change this to
//	  7 8 9 10 1 2 3 4 5 6
//		reverse 1 .. 6 :    6 5 4 3 2 1 7 8 9 10
//		reverse 7 .. 10     6 5 4 3 2 1 10 9 8 7
//		reverse all :       7 8 9 10 1 2 3 4 5 6

