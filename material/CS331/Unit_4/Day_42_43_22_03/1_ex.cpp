// partial template class specialization
#include <iostream>
using namespace std;
#include <string>

template <typename T1, typename T2> class A
{
  public:
    static void disp() { cout << "zero\n"; }
};

template <typename T> class A<T, T>
{
  public:
    static void disp() { cout << "one\n"; }
};

template <typename T1, typename T2> class A<T1 *, T2 *>
{
  public:
    static void disp() { cout << "two\n"; }
};

template <typename T> class A<T, int>
{
  public:
    static void disp() { cout << "three\n"; }
};

template <> class A<int *, int *>
{
  public:
    static void disp() { cout << "four\n"; }
};

template <> class A<int, int>
{
  public:
    static void disp() { cout << "five\n"; }
};

class X
{
    char *p;
};
using mytype = X *;

int main()
{
    A<double, char> a1;
    a1.disp(); // zero
    A<double, int> a2;
    a2.disp(); // three
    A<int, int> a3;
    a3.disp(); // five
    //	A<double*, double*> a4; a4.disp(); // error one or two; both are equally
    // specialized
    A<double *, int *> a5;
    a5.disp(); // two
    A<int *, int *> a6;
    a6.disp(); // four
    A<int, int> a7;
    a7.disp(); // five
    A<char, char> a8;
    a8.disp(); // one
    A<string, string> a9;
    a9.disp(); // one
    // A<mytype, mytype> a10; a10.disp(); // ambiguity
    A<X, X> a11;
    a11.disp(); // one
}
