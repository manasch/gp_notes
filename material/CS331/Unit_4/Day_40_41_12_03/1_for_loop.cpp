#include <iostream>
using namespace std;

// range_for
//		always traverses the whole container
//		cannot get an iterator from here
int main()
{
    int a[] = {11, 22, 33, 44, 55};
    // 1. 'C' for loop
    // 2. loop based on iterator
    // 3. range_for
    for (int e : a) // e : gets a copy; value semantics
    {
        cout << e << "\t";
        e += 100;
    }
    cout << "\n";
    for (int e : a)
    {
        cout << e << "\t";
    }
    cout << "\n";

    for (int &e : a) // e : gets a reference; reference semantics
    {
        cout << e << "\t";
        e += 100;
    }
    cout << "\n";

    for (int e : a)
    {
        cout << e << "\t";
    }
    cout << "\n";
}
