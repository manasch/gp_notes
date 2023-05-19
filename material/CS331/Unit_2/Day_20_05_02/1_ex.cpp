#include <iostream>
using namespace std;

class MyNum
{
	private:
	int n_;
	public:
	MyNum(int n = 0) : n_(n) { }
//	int find_sqr() const { return n_ * n_; }
	friend int sqr(MyNum);
};
int sqr(MyNum y)
{
//	return y.find_sqr();
	return y.n_ * y.n_;
}
int main()
{	
	MyNum x(10);
//	cout << x.find_sqr() << "\n";
	cout << sqr(x) << "\n";
}
