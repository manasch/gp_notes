#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
class Complex
{
  private:
    int rp_;
    int ip_;

  public:
    Complex(int rp = 0, int ip = 0) : rp_(rp), ip_(ip) {}
    friend ostream &operator<<(ostream &o, const Complex &c);
    friend bool operator==(const Complex &lhs, const Complex &rhs);
};
bool operator==(const Complex &lhs, const Complex &rhs)
{
    return lhs.rp_ == rhs.rp_ && lhs.ip_ == rhs.ip_;
}
ostream &operator<<(ostream &o, const Complex &c)
{
    return o << c.rp_ << ":" << c.ip_;
}
struct Odd
{
    bool operator()(int x) { return x % 2; }
};
template <typename ptr_t, typename unary_op_t>
ptr_t myfind_if(ptr_t first, ptr_t last, unary_op_t op)
{
    while (first != last && !op(*first))
    {
        ++first;
    }
    return first;
}

int main()
{
    int a[] = {32, 22, 14, 21, 9, 42, 5};
    vector<int> v(a, a + 7);
    // find 9
    vector<int>::iterator it = find(begin(v), end(v), 9);
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }

    // find an odd number

    //	it = find_if(begin(v), end(v), Odd());
    it = myfind_if(begin(v), end(v), Odd());
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }

    Complex c[]{{1, 3}, {5, 2}, {2, 4}, {8, 2}, {6, 7}};
    vector<Complex> vc(c, c + 5);
    vector<Complex>::iterator itc = find(begin(vc), end(vc), Complex(2, 4));
    if (itc == end(vc))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *itc << "\n";
    }
}
