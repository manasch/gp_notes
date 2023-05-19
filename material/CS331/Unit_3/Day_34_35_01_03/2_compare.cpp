#include <iostream>
using namespace std;
#include <vector>
#include <deque>

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
template<typename ptr1_t, typename ptr2_t>
bool are_same(ptr1_t first1, ptr1_t last1, ptr2_t first2, ptr2_t last2)
{
	while(first1 != last1 && first2 != last2 && *first1 == *first2)
	{
		++first1;
		++first2;
	}
	return first1 == last1 && first2 == last2;
}
template<typename ptr1_t, typename ptr2_t, typename op_t>
bool are_same(ptr1_t first1, ptr1_t last1, ptr2_t first2, ptr2_t last2, op_t op)
{
	while(first1 != last1 && first2 != last2 && op(*first1, *first2))
	{
		++first1;
		++first2;
	}
	return first1 == last1 && first2 == last2;
}
struct MyEqual
{
	bool operator()(int x, int y) { return x % 10 == y % 10; }
};
int main()
{
	int a[] = {11, 22, 33, 44, 55, 66, 77};
	vector<int> v(begin(a), end(a));
	cout << boolalpha;
	cout << are_same(begin(a), end(a), begin(v), end(v)) << "\n";
	deque<int> d(a, a + 5);
	cout << are_same(begin(d), end(d), begin(v), end(v)) << "\n";
	
	cout << are_same(begin(a), end(a), begin(v), end(v), MyEqual()) << "\n";
	cout << are_same(begin(d), end(d), begin(v), end(v), MyEqual()) << "\n";
	int b[] = {21, 42, 63, 84, 95, 6, 17};
	cout << are_same(begin(a), end(a), begin(b), end(b), MyEqual()) << "\n";
	
}
