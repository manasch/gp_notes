#include <iostream>
using namespace std;
#include <typeinfo>
// template parameters can have defaults
template<typename T = char>
class A
{
};

int main()
{
	{
		A<int> a1;
		cout << "a1 : " << typeid(a1).name() << "\n";
		A<double> a2;
		cout << "a2 : " << typeid(a2).name() << "\n";
		A<A<bool>> a3;
		cout << "a3 : " << typeid(a3).name() << "\n";
		A<> a4;
		cout << "a4 : " << typeid(a4).name() << "\n";
	
	}
}
// typeid : an operator
//			syntactically similar to sizeof
//			operand : expression or typename
//			instantiates of class : typeinfo
//			implementation class
//			only way of instantiation
//			supports 
//				==
//				!=
//				char* name(); // implementation
//			runtime mechanism : RTTI : Run Time Type Identification


