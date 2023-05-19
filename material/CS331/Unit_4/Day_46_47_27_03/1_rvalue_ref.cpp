#include <iostream>
using namespace std;

// & operator to an entity : lvalue
// cannot apply & operator : rvalue

int main()
{
    int a(10);
    int &r(a);   // l value reference ; r : lvalue reference
    int &&x(10); // x is a r value reference; x can be changed; x is a lvalue
    // x refers to a r value
    cout << x << "\n";
    x = 20;
    cout << x << "\n";
    cout << &r << '\n';
    cout << &x << '\n';
    // int&& y(a); // cannot bind rvalue reference to lvalue of type int

    int &&z(move(a)); // converts a lvalue to a rvalue
    cout << z << "\n";
}
