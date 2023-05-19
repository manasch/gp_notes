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
// type of p : fixed at compile time
// value of p : depends on the call;  fixed at runtime
void caller(void (*p)())
{
	p(); // (*p)(); // cannot be inlined
}
int main()
{
	caller(foo);
	caller(bar);
}
