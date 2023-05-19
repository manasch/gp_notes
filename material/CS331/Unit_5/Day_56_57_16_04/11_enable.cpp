#include <iostream>
using namespace std;
#include <type_traits>
#include <typeinfo>

class Complex
{
  private:
    double rp_;
    double ip_;

  public:
    Complex(double rp, double ip) : rp_(rp), ip_(ip) {}
    friend ostream &operator<<(ostream &o, const Complex &c);
    friend Complex add(const Complex &lhs, const Complex &rhs);
};

ostream &operator<<(ostream &o, const Complex &c)
{
    return o << c.rp_ << "\t" << c.ip_ << "\n";
}

Complex add(const Complex &lhs, const Complex &rhs)
{
    return Complex(lhs.rp_ + rhs.rp_, lhs.ip_ + rhs.ip_);
}
// does not compile !!
template <typename T> T double_it(T x)
{
    if (typeid(T) == typeid(Complex))
        return add(x, x);
    else
        return x + x;
}

int main()
{
    cout << double_it(10) << "\n";
    Complex c(3, 4);
    cout << double_it(c) << "\n";
}
