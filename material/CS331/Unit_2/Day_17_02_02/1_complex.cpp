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


Complex Complex::add(const Complex& rhs) const
{
#if 0
	Complex res;
	res.rp_ = rp_ + rhs.rp_;
	res.ip_ = ip_ + rhs.ip_;
	return res;
#endif
	Complex res(rp_ + rhs.rp_, ip_ + rhs.ip_);
	return res;
}

void Complex::disp() const
{
	cout << rp_ << ":" << ip_ << "\n";
}




