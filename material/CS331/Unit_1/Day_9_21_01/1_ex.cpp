#include <iostream>
using namespace std;
// pointers:
//		alias
//		garbage => memory leak : on heap :  location; no access
//		dangling pointer => no location; access

int main()
{
	int a[] = {10, 20, 30, 40, 50};
	int *p(a + 5);
	// dangling pointer : no location; access
	// dangling pointers are not dangerous
	// dereferencing dangling pointer is dangerous
	
	cout << a << "\t" << p << "\n";
	cout << (p - a) << "\n";
	cout << *(p - 2) << "\n";
	// cout << *p << "\n"; // undefined behaviour
}
