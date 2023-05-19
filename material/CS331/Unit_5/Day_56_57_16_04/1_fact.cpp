#include <iostream>
using namespace std;

template <int N> struct Fact
{
    enum
    {
        res = N * Fact<N - 1>::res
    };
};

template <> struct Fact<0>
{
    enum
    {
        res = 1
    };
};

int main()
{
    cout << "fact of 0 : " << Fact<0>::res << "\n";
    cout << "fact of 5 : " << Fact<5>::res << "\n";
}
