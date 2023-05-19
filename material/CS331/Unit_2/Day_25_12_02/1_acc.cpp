
#include <iostream>
using namespace std;
class MyVector
{
	public:
	explicit MyVector(int n);
	~MyVector();
	MyVector(const MyVector&) = delete;
	MyVector& operator=(const MyVector&) = delete;
	// class which supports the concept of position
	// opaque object 
	// pointer like object
	class Iterator
	{
		public:
		Iterator(int* p_it) : p_it_(p_it) { }
		Iterator& operator++() // pre
		{
			++p_it_;
			return *this;
		}
		Iterator operator++(int) // post
		{
			Iterator temp(*this);
			++*this;
			return temp;
		}
		int operator*()
		{
			return *p_it_;
		}
		bool operator==(const Iterator& rhs) const
		{
			return p_it_ == rhs.p_it_;
		}
		bool operator!=(const Iterator& rhs) const
		{
			return !(*this == rhs);
		}
		private:
		int *p_it_;
	};
	Iterator begin()
	{
		return Iterator(p_);
	}
	Iterator end()
	{
		return Iterator(p_ + n_);
	}
	private:
	int* p_;
	int n_;
};
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
// functor class
struct Add
{
	int operator()(int x, int y) { return x + y; }
};
// ptr_t should support:
// != == 
// * dereferencing operator : rvalue usage
// ++ (pre and post)
template<typename ptr_t, typename T, typename binop_t>
T acc(ptr_t first, ptr_t last, T init, binop_t op)
{
#if 1
	while(first != last)
	{
		init = op(init, *first);
		++first;
	}
#endif
	return init;
}
int main()
{
	int a[] = {3, 1, 5, 2, 4};
	cout << "acc : " << acc(a, a + 5, 0, Add() ) << "\n";
	MyVector v(5);
	cout << "acc : " << acc(v.begin(), v.end(), 0, Add() ) << "\n";
	// MyVector::Iterator
}




