#include <iostream>
using namespace std;

template<typename T>
struct Is_Pointer
{
	enum { res = 0 };
};

template<typename T>
struct Is_Pointer<T*>
{
	enum { res = 1 };
};
template<typename T>
bool foo(T t)
{
	return Is_Pointer<T>::res;
}
int main()
{
	cout << boolalpha;
	int n(10); int *p(&n);
	cout << "is pointer : " << foo(n) << "\n";
	cout << "is pointer : " << foo(&n) << "\n";
	cout << "is pointer : " << foo(p) << "\n";
	
}
