#include <iostream>
using namespace std;

class MyVector
{
	public:
	explicit MyVector(int n);
	~MyVector();
	MyVector(const MyVector&) = delete;
	MyVector& operator=(const MyVector&) = delete;
	friend ostream& operator<<(ostream& o, const MyVector&);
	private:
	int* p_;
	int n_;
};
ostream& operator<<(ostream& o, const MyVector& v)
{
	for(int i = 0; i < v.n_; ++i)
	{
		o << v.p_[i] << "\t";
	}
	return o << "\n";
}

MyVector::MyVector(int n)
: n_(n), p_(new int[n])
{
	for(int i = 0; i < n; ++i)
	{
		p_[i] = i * i;
	}
}
MyVector::~MyVector()
{
	delete [] p_;
}

void foo(const MyVector&)
{
	cout << "foo called\n";
}
int main()
{
	MyVector v(5);  cout << v << "\n";
	foo(v);
//	foo(10000); // foo(MyVector(10000));
}



