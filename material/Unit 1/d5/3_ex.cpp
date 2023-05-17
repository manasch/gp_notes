#include <iostream>
using namespace std;
// function
// prototype or fn declaration:
//	1. match arguments to parameters
//		#, type and order
//		types do not match => might introduce casting
//  2. overloading
//	3. default parameters

// matching of arguments to parameters:
// 1. exact match or trivial conversions
// 2. generic function
// 3. promotion
//		integral type to int
//		flaot type to double
//		no loss of precision
//		int and double are the preferred type
// 4. standard conversion
//		numeric conversion
// 5. user defined conversion
// 6. type unsafe function

int add(int, int);

// overload:
//	more than one function has the same name
void foo(int x) { cout << "foo int\n"; }
void foo(double x) { cout << "foo double\n"; }
int main()
{
    cout << "res : " << add(3, 4) << "\n";
    // cout << "res : " << add(3, 4, 5) << "\n"; // compile time error
    cout << "res : " << add(3.5, 4.6) << "\n";
    foo(20);
    foo(2.0);
}

int add(int x, int y) { return x + y; }
