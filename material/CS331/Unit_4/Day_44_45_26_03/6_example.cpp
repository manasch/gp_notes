#include <iostream>
using namespace std;

class A
{
};
class B : public A
{
};
class C : public B
{
};

void foo(B b) { cout << "B::foo called\n"; } // called !!
void foo(A a) { cout << "A::foo called\n"; }

int main()
{
    C c;
    foo(c);
}
