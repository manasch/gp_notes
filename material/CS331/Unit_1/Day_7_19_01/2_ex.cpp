#include <iostream>
using namespace std;


#if 0
int sq(int x)
{
	return x * x;
}

double sq(double x)
{
	return x * x;
}
#endif

template<typename T>
T sq(T x)
{
	return x * x;
}

template<typename T>
bool eq(T a, T b)
{
	return a == b;
}

int main()
{
#if 0
	cout << sq(10) << "\n";
	cout << sq(1.5) << "\n";
	cout << sq(20) << "\n";
	cout << sq(2.5f) << "\n";
#endif
	cout << boolalpha; // manipulator
	//cout << eq(65, 65) << "\n";
	//cout << eq('A', 'A') << "\n";
	// cout << eq('A', 65) << "\n"; // ambiguity; two possible values for T
	
	cout << eq<int>('A', 65) << "\n";
	
}



