

// * STL goal:
// * efficiency                     
// * no inheritance for polymorphic usage
// * no virtual functions
// * object based and not object oriented
// * Will understand all these terms in next day
#include <iostream>
using namespace std;

//! Some standard containers - usage
#include <deque>
#include <list>
#include <vector>

template <typename ptr_t> 
void disp(ptr_t first, ptr_t last) //! using a pair
{
    while (first != last)
    {
        cout << *first << "\t";
        ++first;
    }
    cout << "\n";
}
int main()
{
    int a[] = {11, 22, 33, 44, 55};
    disp(a, a + 5);

    // * template < class T, class Alloc = allocator<T> >
    // * class vector;
    vector<int> v(a, a + 5); // * vector<int, allocator<int>>
    disp(v.begin(), v.end());
    // * pair of iterators abstracts away the container

    vector<int> v1(v.begin(), v.end()); // * vector<int, allocator<int>>
    disp(v1.begin(), v1.end());

    // * template < class T, class Alloc = allocator<T> >
    // * class deque;
    deque<int> d(v1.begin(), v1.end());
    disp(d.begin(), d.end());

    list<int> l(v1.begin(), v1.end());
    disp(l.begin(), l.end());
}
