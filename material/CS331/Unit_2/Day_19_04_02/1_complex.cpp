#include <iostream>
using namespace std;
#include "1_complex.h"

Complex::Complex(double rp, double ip)
: rp_(rp), ip_(ip)
{
}
// any private member of a class is accessible in the member function
//	by any object of the class which has scope in that function
//	- global
//	- static external
//	- internal static
//	- parameter
//	- local
//	- temp

// return by reference? NO
// what if res is static?
// what if result is a dynamic object?

// return object optimization
Complex Complex::add(const Complex& rhs) const
{
#if 0
	Complex res;
	res.rp_ = rp_ + rhs.rp_;
	res.ip_ = ip_ + rhs.ip_;
	return res;
#endif
#if 0
	Complex res(rp_ + rhs.rp_, ip_ + rhs.ip_);
	return res;
#endif
	return Complex(rp_ + rhs.rp_, ip_ + rhs.ip_);
}

#if 0
Complex Complex::operator+(const Complex& rhs) const
{	
	return Complex(rp_ + rhs.rp_, ip_ + rhs.ip_);
}
#endif

// free function : operator+
Complex operator+(const Complex& lhs, const Complex& rhs)
{	
	return Complex(lhs.rp_ + rhs.rp_, lhs.ip_ + rhs.ip_);
}

void Complex::disp() const
{
	cout << rp_ << ":" << ip_ << "\n";
}
/*
	return ref to static variable
	c1.add(c2) == c3.add(c4) always true
*/
ostream& operator<<(ostream& o, const Complex& c)
{
	return o << "( " << c.rp_ << "," << c.ip_ << ") ";
}


