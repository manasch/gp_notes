#include <iostream>
using namespace std;
struct Add
{
	int operator()(int x, int y) { return x + y; }
};

int add(int x, int y)
{
	return Add()(x, y);
}

// object closure:
//	callable with state
// holds the state
struct Add1
{
	Add1(int x) : x_(x) { }
	int operator()(int y) { return add(x_, y); } 
	int x_;
	
};

int add1(int y)
{
	return Add1(20)(y);
}
int main()
{
	cout << add(20, 10) << "\n";
	cout << add1(10) << "\n"; // 30  // use add here to
	cout << add1(30) << "\n"; // 50
}
