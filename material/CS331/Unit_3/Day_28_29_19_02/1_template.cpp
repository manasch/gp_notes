#include <iostream>
using namespace std;
#include <typeinfo>
// instantiate a class template:
//	- explicit instantiation
//	- default parameters

// template parameters can have defaults
template <typename T = char> class A
{
};

template <typename T1 = int, typename T2 = bool> class B
{
};

template <typename T1 = int, typename T2 = T1> class C
{
};

template <typename T1 = int, typename T2 = A<T1>> class D
{
};

int main()
{
    {
        A<int> a1;
        cout << "a1 : " << typeid(a1).name() << "\n";
        A<double> a2;
        cout << "a2 : " << typeid(a2).name() << "\n";
        A<A<bool>> a3; // nested instantiation
        cout << "a3 : " << typeid(a3).name() << "\n";
        A<> a4; // default parameter
        cout << "a4 : " << typeid(a4).name() << "\n";
    }
    {
        B<char, int> a1;
        cout << "a1 : " << typeid(a1).name() << "\n";
        B<float> a2;
        cout << "a2 : " << typeid(a2).name() << "\n";
        B<A<bool>> a3; // nested instantiation
        cout << "a3 : " << typeid(a3).name() << "\n";
        B<> a4; // default parameter
        cout << "a4 : " << typeid(a4).name() << "\n";
    }
    {
        C<char, int> a1;
        cout << "a1 : " << typeid(a1).name() << "\n";
        C<float> a2;
        cout << "a2 : " << typeid(a2).name() << "\n";
        C<> a4; // default parameter
        cout << "a4 : " << typeid(a4).name() << "\n";
    }
    {
        D<char, int> a1;
        cout << "a1 : " << typeid(a1).name() << "\n";
        D<float> a2;
        cout << "a2 : " << typeid(a2).name() << "\n";
        D<> a4; // default parameter
        cout << "a4 : " << typeid(a4).name() << "\n";
    }
}
