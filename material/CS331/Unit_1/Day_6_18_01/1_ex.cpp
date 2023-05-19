#include <iostream>
using namespace std;
void f(int) { cout << "f int\n"; }
void f(double) { cout << "f double\n"; }
void f(char) { cout << "f char\n"; }
// declaration can be repeated; defn cannot
// scope rules come into play
int main()
{
	//f('a');
	//f(2.5f);
	//f(25);
	
	void f(char); 
	f(25);
	::f(25);
}
