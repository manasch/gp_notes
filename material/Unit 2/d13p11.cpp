#include<iostream>
#include<typeinfo>
using namespace std;
template<typename X>
class Base {
public:
int basefield;
using T = int;
};

template<typename T>
class D2 : public Base<double> { // nondependent base
public:
void f() { basefield = 7; } // usual access to inherited member
T strange; // T is Base<double>::T, not the template parameter!
};
void g (D2<int*>& d2, double * p)
{
d2.strange = p; // ERROR: type mismatch!
}
int main()
{
}
