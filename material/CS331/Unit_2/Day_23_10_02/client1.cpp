#include <iostream>
using namespace std;
// fn call op : functor
class Ex // functor class
{
	public:
	Ex(int, int) { cout << "ctor call\n"; }
	void operator()(int, int) { cout << "fn call operator\n"; }
};
// an object of a functor class : callable
int main()
{
	Ex ex(10, 20);
	Ex(30, 40);
	ex(50, 60); // fn call op call  ; Ex::operator()(50, 60)
	ex.operator()(11, 22);
	cout << "\n";
	Ex(1, 2)(3, 4);

}
