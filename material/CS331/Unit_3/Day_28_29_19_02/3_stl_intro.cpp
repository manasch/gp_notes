/*
STL : Standard Template Library
        library of data structures and algorithms
        designed by Stepanov - mid 1990s
        developed at HP and CGI
        collection of template classes and functions
        goal:	efficiency
                        no inheritance for polymorphic usage
                        no virtual functions
                        object based and not object oriented

STL has:
1. containers
2. algorithms
3. iterators
4. functors
5. adaptors
6. allocator

book : STL tutorial and reference : Musser and Saini

containers:
- sequential containers
        - array
                fixed size, const time access
        - vector
                variable size, const time access, insert at one end is const
time
        - deque
                variable size, const time access, insert at either end is const
time
        - list
                variable size, linear time access, insert any place is const
time
- sorted associative containers
        - set
        - multiset
        - map
        - multimap
- unordered containers
        - set
        - map
*/

#include <iostream>
using namespace std;
#include <deque>
#include <list>
#include <vector>

template <typename ptr_t> void disp(ptr_t first, ptr_t last)
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

    // template < class T, class Alloc = allocator<T> > class vector;
    vector<int> v(a, a + 5); // vector<int, allocator<int>>
    disp(v.begin(), v.end());
    // pair of iterators abstracts away the container

    vector<int> v1(v.begin(), v.end()); // vector<int, allocator<int>>
    disp(v1.begin(), v1.end());

    // template < class T, class Alloc = allocator<T> > class deque;
    deque<int> d(v1.begin(), v1.end());
    disp(d.begin(), d.end());

    list<int> l(v1.begin(), v1.end());
    disp(l.begin(), l.end());
}
