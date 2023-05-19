#include <iostream>
using namespace std;

void foo()
{
	cout << "foo called\n";
}
void bar()
{
	cout << "bar called\n";
}

int main()
{
	void (*p)();
	p = foo;
	p();
	p = bar;
	p();
}
