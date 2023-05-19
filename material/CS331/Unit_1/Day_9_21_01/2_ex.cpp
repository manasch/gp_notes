#include <iostream>
using namespace std;

#if 0
void disp(int* first, int* last)
{
#if 0
	//while(first <= last) // invalid
	while(first < last)
	{
		cout << *first++ << "\t";
	}
	cout << "\n";
#endif
	while(first != last)
	{
		cout << *first << "\t";
		++first;
	}
	cout << "\n";
}
#endif

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
	//int a[] = {10, 20, 30, 40, 50, -1}; // -1 is a sentinel
	// different ways of passing array as argument
	// disp(a, 5);
	// disp(a); // with a sentinel
	// disp(a, a + 4); // two pointers; first : points to the beginning
	//	second : points to the last element
	// disp(a, a + 5); // two pointers; first : points to the beginning
	// second : pointer one past the end
	
	int a[] = {10, 20, 30, 40, 50};
	disp(a, a + 5);	
	
	double b[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	disp(b, b + 5);
	
}
	
