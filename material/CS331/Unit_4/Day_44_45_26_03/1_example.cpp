//  swap two elements of a container
#include <iostream>
using namespace std;
#include <list>
#include <vector>
template <typename T> void myswap_(T &x, T &y)
{
    T temp(x);
    x = y;
    y = temp;
}

template <typename ptr_t> void myswap(ptr_t one, ptr_t two)
{
    myswap_(*one, *two);
}

int main()
{
    vector<int> v{11, 22, 33, 44, 55};
    for (auto e : v)
        cout << e << "\t";
    cout << "\n";
    myswap(begin(v), begin(v) + 1);
    for (auto e : v)
        cout << e << "\t";
    cout << "\n";

    list<int> l{11, 22, 33, 44, 55};
    for (auto e : l)
        cout << e << "\t";
    cout << "\n";
    myswap(begin(l), ++begin(l));
    for (auto e : l)
        cout << e << "\t";
    cout << "\n";
}
