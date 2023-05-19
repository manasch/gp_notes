#include <iostream>
using namespace std;

int foo(int x) { return x; }

int main()
{
    cout << foo(2.5) << "\n";
    cout << foo({}) << "\n";
    //	cout << foo({2.5}) << "\n";
}
// parameter passing :
//	argument is copied to the corresponding parameter
// return mechanism
//	return value is copied to the temporary associated with return
// these are initialization and not assignment
