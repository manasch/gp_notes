// given an iterator, find the iterator after n steps
// advance the iterator by some number n
#include <iostream>
using namespace std;
#include <list>
#include <vector>
template <typename ptr_t>
ptr_t my_advance_(ptr_t it, int n, random_access_iterator_tag)
{
    cout << "random access\n";
    return it + n;
}

template <typename ptr_t> ptr_t my_advance_(ptr_t it, int n, input_iterator_tag)
{
    cout << "inut iterator\n";
    while (n--)
    {
        ++it;
    }
    return it;
}
template <typename ptr_t> ptr_t my_advance(ptr_t it, int n)
{
    return my_advance_(it, n,
                       typename iterator_traits<ptr_t>::iterator_category());
}

int main()
{
    vector<int> v{11, 22, 33, 44, 55};
    vector<int>::iterator it_v = begin(v);
    it_v = my_advance(it_v, 3);
    cout << "val : " << *it_v << "\n";

    list<int> l{11, 22, 33, 44, 55};
    list<int>::iterator it_l = begin(l);
    it_l = my_advance(it_l, 3);
    cout << "val : " << *it_l << "\n";
}
/*
class input_iterator_tag { };
class output_iterator_tag { };
class forward_iterator_tag : public input_iterator_tag,  output_iterator_tag {
}; class bidirectional_iterator_tag : public forward_iterator_tag { }; class
random_access_iterator_tag : public bidirectional_iterator_tag { };

class A
{
        public:
        int a;
};
class B : public A
{
        public:
        int b;
};
A x;
B y;
// slicing : base class members of y are assigned to members of x
x = y; // x.a = y.a;


*/
