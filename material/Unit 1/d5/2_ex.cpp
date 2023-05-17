#include <iostream>
using namespace std;
#include <vector>

int main()
{
	cout << "one\n";
	// initialization
	int a = 10;
	int b(20); // preferred
	int c{30};
	// int d{2.5}; // narrowing not allowed
	
	// uniform initialization
	int e[5]{11, 22, 33, 44, 55};
	
	cout << a << "\t" << b << "\t" << c << "\n";
	for(int x : e) // range for
	{
		cout << x << "\t";
	}
	cout << "\n";
	
	vector<int> f{10, 20, 30, 40, 50};
	for(int x : f) // range for
	{
		cout << x << "\t";
	}
	cout << "\n";
	
	
}
