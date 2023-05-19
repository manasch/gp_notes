/*
set :
        unique elements
        ordered based on a predicate
        no control over the positioning - cannot insert at pos x


*/
#include <iostream>
using namespace std;
#include "date.h"
#include <algorithm>
#include <set>
#include <string>

template <typename ptr_t> void disp(ptr_t first, ptr_t last)
{
    while (first != last)
    {
        cout << *first << "\t";
        ++first;
    }
    cout << "\n";
}

template <typename T> class MyLess
{
  public:
    bool operator()(const T &lhs, const T &rhs) { return lhs < rhs; }
};
struct What
{
    bool operator()(int lhs, int rhs) { return lhs % 10 < rhs % 10; }
};
struct SameMonth
{
    bool operator()(const Date &lhs, const Date &rhs)
    {
        return lhs.compare_month(rhs);
    }
};
int main()
{
    less<string> l;
    cout << boolalpha;
    cout << l("amar", "bharath") << "\n";
    MyLess<string> l1;
    cout << l1("amar", "bharath") << "\n";

    set<int> s1{10, 5, 2, 10, 5, 22, 7, 17, 10, 5, 2};
    disp(begin(s1), end(s1));

    set<int, less<int>> s2{10, 5, 2, 10, 5, 22, 7, 17, 10, 5, 2};
    disp(begin(s2), end(s2));

    set<int, What> s3{10, 5, 12, 2, 10, 5, 22, 7, 17, 10, 5, 2};
    disp(begin(s3), end(s3));

    Date d1[] = {{30, 1, 1948},  {11, 1, 1966}, {11, 9, 2001}, {26, 1, 2001},
                 {30, 1, 1948},  {11, 9, 2001}, {11, 1, 1966}, {30, 1, 1948},
                 {26, 12, 2004}, {11, 9, 2001}};
    //	set<Date> s4(begin(d1), end(d1));
    set<Date, less<Date>> s4(begin(d1), end(d1));
    disp(begin(s4), end(s4));

    Date d[] = {{11, 9, 2001},
                {26, 1, 2001},
                {11, 1, 1966},
                {30, 1, 1948},
                {26, 12, 2004}};
    set<Date, SameMonth> s5(begin(d), end(d));
    disp(begin(s5), end(s5));
    // --------------------------------------------

    // find : on s4
    set<Date, less<Date>>::iterator it = s4.find({11, 9, 2001});
    if (it == end(s4))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }
// *it = Date(1, 1, 1970); // Error
#if 1
    // generic find:
    //	T : operator==
    it = find(begin(s4), end(s4), Date{11, 9, 2001});
    if (it == end(s4))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }
#endif
}

// member find:

// !(a < b) &&  !(b < a)   => a == b
