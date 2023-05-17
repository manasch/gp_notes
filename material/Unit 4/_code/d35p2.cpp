#include <iostream>
using namespace std;
class A
{
public:
virtual void disp()
{
cout << " Message from the class A \n ";
}
};
class B :public A
{
public:
void disp()
{
cout << "Message from the class B\n";
}
};
int main()
{
A* obj1;       // super class pointer
B obj2;     // child class object
obj1 = &obj2;
obj1-> disp();     // Dynamic Binding Ocuurs
}