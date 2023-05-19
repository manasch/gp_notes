// playing with types
#include <iostream>
using namespace std;
template <typename T> T sum(T a[], int n)
{
    T s = T();
    for (int i = 0; i < n; ++i)
    {
        s += a[i];
    }
    return s;
}

// develop mapping of types
template <typename T> struct MyTraits;

template <> struct MyTraits<int>
{
    using RT = int;
};
template <> struct MyTraits<char>
{
    using RT = int;
};

template <typename T> typename MyTraits<T>::RT sum1(T a[], int n)
{
    using RT = typename MyTraits<T>::RT;
    RT s = RT();
    for (int i = 0; i < n; ++i)
    {
        s += a[i];
    }
    return s;
}

template <typename T, typename RT = typename MyTraits<T>::RT>
RT sum2(T a[], int n)
{
    RT s = RT();
    for (int i = 0; i < n; ++i)
    {
        s += a[i];
    }
    return s;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    char b[] = {'a', 'b', 'c', 'd', 'e'};
    cout << "average : " << sum(a, 5) / 5 << "\n";
    cout << "average : " << sum(b, 5) / 5 << "\n";
    cout << "average : " << sum1(a, 5) / 5 << "\n";
    cout << "average : " << sum1(b, 5) / 5 << "\n";

    cout << "average : " << sum2<int, int>(a, 5) / 5 << "\n";
    cout << "average : " << sum2<char, int>(b, 5) / 5 << "\n";

    cout << "average : " << sum2(a, 5) / 5 << "\n";
    cout << "average : " << sum2(b, 5) / 5 << "\n";
}
