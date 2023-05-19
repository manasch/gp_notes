#include <iostream>
using namespace std;
class A
{
    public:
    A(){};
    A(const A& b){cout<<"copy";}
    A(A&& a){cout<<"move";}
 }
;
void foo(A&& x)
{
    cout<<"foo";
};
int main()
{
    A a;
    foo(a);
}
