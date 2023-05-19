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
	
	// explicit : suppresses implicit conversion
	//	using explicit is a rule
	//	not using is an exception
	//	meaningful for single argument ctor
	// explicit 
	Complex(double rp = 0.0, double ip = 0.0);
	void disp() const;
	Complex add(const Complex& rhs) const; // *this : const
//	Complex operator+(const Complex& rhs) const; // *this : const
	friend Complex operator+(const Complex& lhs, const Complex& rhs);
	friend ostream& operator<<(ostream& o, const Complex& c);
};
// friend function:
//	part of the class
//	best possible solution in such cases
//	is an interface of the class
//	does not break encapsulation
//	strengthens encapsulation
//	seldom have friends
//  have friends only when required
//	use friend functions :
//		binary operator with no lvalue usage
//		position of operand is not right
//		convention demands






// add two complex numbers
//	1. void add(const Complex& lhs, const Complex& rhs, Complex& res);
//	2. Complex? add(const Complex& lhs, const Complex& rhs);  

// add three objects ?
//	1. two statements
//  2. cascade   c1.add(c2).add(c3) 
// select # 2

#endif

