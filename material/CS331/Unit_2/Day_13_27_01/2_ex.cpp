// ctor and dtor calls
#include <iostream>
using namespace std;

class A
{
	private: // are interface for the class developer; implementation for the client
	// accessible in any function of the class
	const int x_;
	const int y_;
	public:
	A(int, int);
	void disp();
};
#if 0
A::A(int x, int y)
{
	cout << "ctor\n";
	x_ = x; // if member is a const, it cannot be assigned
	y_ = y;
}
#endif
// member initialization list:
//	only with the ctor
//	required:
//		const member
//		reference member
//		base class subobject
//  order of initialization:
//		not the order in which we specify
//		1.
//		2.
//		3. order of declaration of members in the class
//			top to bottom
//			left to right
A::A(int x, int y)
: x_(x), y_(y)
// : x_(y_), y_(100) // x_ undefined value
// : y_(100), x_(y_) // x_ undefined value

{
	cout << "ctor\n";

}
// any function of the class will have an implicit parameter
// - will point to the object thro' which the call is made
// - this parameter is always called : this
// -this : keyword; const pointer
void A::disp()
{
//	cout << this->x_ << "\t" << this->y_ << "\n";
	cout << x_ << "\t" << y_ << "\n";
	// all unqualifed names are prefixed with this->
	

}

int main()
{
	//A a1; // compile time error; no default ctor
	A a2(10, 20);
	a2.disp(); // A::disp(&a2);
}
// can we call the dtor explicitly?
// 	a2.~()
// if the dtor can be called, and is called, does the object die?
// if the dtor can be called, and is called, object does not die - 
//	would the dtor be called when the object does die?
// can we call the ctor explicitly?
//	a2.A() 



