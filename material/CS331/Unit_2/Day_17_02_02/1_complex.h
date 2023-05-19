#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
	private:
	double rp_;
	double ip_;
	public:
	// constructor:
	//	two arg ctor
	//	single arg ctor
	//	default ctor
	Complex(double rp = 0.0, double ip = 0.0);
	void disp() const;
	Complex add(const Complex& rhs) const; // *this : const
	
};
// add two complex numbers
//	1. void add(const Complex& lhs, const Complex& rhs, Complex& res);
//	2. Complex? add(const Complex& lhs, const Complex& rhs);  

// add three objects ?
//	1. two statements
//  2. cascade   c1.add(c2).add(c3) 
// select # 2

#endif

