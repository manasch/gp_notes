#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

// * algorithm : 
// *	free functions
// *	not part of the class
// *	efficiency : expressed in amortized way

// * 1. find :
// *		returns the position if element is found : valid iterator
// *		returns an iterator not in the valid range if element is not found

// * provided
// *	ptr_t supports:
// *		!= ==
// *		*first : rvalue
// *		++ (pre and post)
// *	T supports:
// *		== != 

#define MY
#ifdef MY
template<typename ptr_t, typename T>
ptr_t my_find(ptr_t first, ptr_t last, T t)
{
	while(first != last && !(*first == t))
	{
		++first;
	}
	return first;
}

#endif
// * my_find(v.begin(), v.end(), 22);

// * a pair of pointers(iterators) abstracts away a container
int main()
{
	int a[] = {33, 11, 22, 55, 44};
	int* p;
//*	p = my_find(a, a + 5, 55);
	p = find(a, a + 5, 55);
	if(p == a + 5)
	{
		cout << "not found\n";
	}
	else
	{
		cout << "found : " << *p << "\n";
	}
//*	p = my_find(a, a + 5, 45);
	p = find(a, a + 5, 45);
	if(p == a + 5)
	{
		cout << "not found\n";
	}
	else
	{
		cout << "found : " << *p << "\n";
	}
	vector<int> v(a, a + 5);
//*	vector<int>::iterator it = my_find(v.begin(), v.end(), 22);	
	vector<int>::iterator it = find(v.begin(), v.end(), 22);	
	if(it == v.end())
	{
		cout << "not found\n";
	}
	else
	{
		cout << "found : " << *it << "\n";
	}
 //*   it = my_find(v.begin(), v.end(), 45);
	it = find(v.begin(), v.end(), 45);
	if(it == v.end())
	{
		cout << "not found\n";
	}
	else
	{
		cout << "found : " << *it << "\n";
	}

}

