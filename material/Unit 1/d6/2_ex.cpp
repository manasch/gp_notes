#include <iostream>
using namespace std;
// both these overloads have similar signature
//	but for type
//	similar implementation
// can the compiler generate these functions
//	provided we give a template of it?
/*
int sq(int x)
{
	return x * x;
}

double sq(double x)
{
	return x * x;
}
*/
//template<typename T>
T sq(T x)
{
	return x * x;
}

int main()
{
	cout << sq(10) << "\n";
	cout << sq(1.5) << "\n";
	
}
