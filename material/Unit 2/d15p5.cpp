#include<iostream>
using namespace std;
/*
1. Usually when declaring a friend that 
 is an instance of a function or a class
template, we can express exactly 
which entity is to be the friend.
2.Sometimes it is nonetheless useful to 
express that all instances 
of a template are friends of a class.
*/
template <typename T>
class A {
  private:
    T x;
  public:
    A(T x) : x(x) {}

    template <typename U>
    friend class B;
};

template <typename U>
class B {
  public:
    static void print_x(A<U> &a) {
      cout << a.x << endl;
    }
};

int main() {
  A<int> a(42);
  A<double> b(42.0);
  B<int>::print_x(a);
  B<double>::print_x(b);
  /* Lets see what happens when we put this 
  cppinsights.io  */
  return 0;
}
/*
this will work:
template <typename U>
friend void print_x(A<U> &a);
this wont work:
template<typename T>
class A {
  friend void func<T>(T t); 
  // error: type parameters
  // cannot be specified in friend declaration
};

Note that the friend template declaration 
must name an unqualified function name 
that is not followed by angle brackets. 
This means that the declaration cannot 
include the type parameters
for the friend template


*/