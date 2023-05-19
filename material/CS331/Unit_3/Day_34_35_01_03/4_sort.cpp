#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
// sort :
//	with : user specifies a binary predicate ; 3 arguments
//	without predicate : hardcoded for < comparison ; 2 arguments
// two functions are overloaded


template<typename ptr_t>
void disp(ptr_t first, ptr_t last)
{
	while(first != last)
	{
		cout << *first << "\n";
		++first;
	}
	cout << "\n";
} 
class Complex
{
	private:
	double rp_;
	double ip_;
	public:
	Complex(double rp = 0, double ip = 0) : rp_(rp), ip_(ip) { } 
	friend ostream& operator<<(ostream& o, const Complex& c);
	//friend bool operator<(const Complex& lhs, const Complex& rhs);
	
	operator double() const { return ip_; } 
};
ostream& operator<<(ostream& o, const Complex& c)
{
	return o << c.rp_ << ":" << c.ip_ ;
}
#if 0
bool operator<(const Complex& lhs, const Complex& rhs)
{
	return lhs.rp_ < rhs.rp_;
}
#endif

template<typename T>
struct MyCmp
{
	bool operator()(const T& x, const T& y) { return x > y; }
};
int main()
{
	int a[] = {33, 22, 1, 21, 9, 42, 5};
	sort(begin(a), end(a), MyCmp<int>());
	disp(begin(a), end(a));
	cout << "\n";
	#if 0
	Complex c[] { {1.0, 3.0}, {5.0, 2.0}, {2.0, 4.0}, {8.0, 2.0}, {6.0, 7.0}
		};
	sort(begin(c), end(c));
	disp(begin(c), end(c));
	#endif
}
// sort:
//	demands < operator
//	On user defined type,
//	a) either provide < operator
//	or
//	b) convert each object to a type on which < operator is defined

