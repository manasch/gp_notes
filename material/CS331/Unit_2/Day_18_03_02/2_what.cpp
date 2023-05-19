#include <iostream>
using namespace std;
class Ex
{
	public:
	Ex() { cout << "ctor\n"; }
	~Ex() { cout << "dtor\n"; }
	
};
int main()
{
	// Ex x;
	//x.~Ex(); // dtor
	// x.Ex(); // no re-initialization
	Ex(); // call ctor explicitly : classname(...)
	// whenever a ctor is called explicitly, the compiler provides an object
	// object will be initialized; temp object
}
