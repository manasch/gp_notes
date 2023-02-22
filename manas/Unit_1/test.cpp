#include <iostream>
#include <typeinfo>
using namespace std;
// class Animal 
// {
//    public:
//       Animal() { 
//          cout << "Animal class constructor invoked!" <<endl; 
//       }
//       ~Animal() { 
//          cout << "Animal class destructor invoked!" <<endl; 
//       }
// };

// int main()
// {
// 	Animal* dog = new(nothrow) Animal; 
// 	Animal* dogs = new(nothrow) Animal[5];
// 	Animal* cat = (Animal*)malloc(sizeof(Animal));
// 	Animal* cats = (Animal*)calloc(5, sizeof(Animal));
// 	return 0;
// }

// void foo(int x) {
//    cout << "Int" << endl;
//    cout << x << endl;
// }

// void foo(double x) {
//    cout << "Double" << endl;
//    cout << x << endl;
// }

// int main() {
//    int f = 3.14;
//    foo(f);
//    cout << typeid(2.0).name() << endl;
//    return 0;
// }

// void f (int) {cout << "f int\n";}
// void f (double) {cout << "f double\n";}
// void f (char) {cout << "f char\n";}

// int main() {
//    // f('a');
//    // f(2.5);
//    // f(25);

//    void f(double);
//    f(25);
//    ::f(25);
//    return 0;
// }

template <typename T = int, typename U>
void func() {
  T i ; U p;
  cout << typeid(i).name() << endl;
  cout << typeid(p).name() << endl;
       
}  
int main()
{
  func<int,int>();
//   func<>();
  func<char,char>();
}
