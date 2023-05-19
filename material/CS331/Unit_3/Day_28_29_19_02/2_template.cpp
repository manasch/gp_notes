#include <iostream>
using namespace std;
#include <string>

template <typename T1, typename T2> struct MyPair
{
    MyPair(T1 first, T2 second) : first(first), second(second) {}
    T1 first;
    T2 second;
};
template <typename T1, typename T2> using p = MyPair<T1, T2>;

// playing with types:
//	to make the life easier:
//  a) typedef
//  b) using
template <typename T1, typename T2>
MyPair<T1, T2> make_MyPair(T1 first, T2 second)
{
    return MyPair<T1, T2>(first, second);
}

int main()
{
    MyPair<string, int> a("vishwanath", 97);
    cout << a.first << ":" << a.second << "\n";
    MyPair<string, int> b("gavaskar", 37);
    cout << b.first << ":" << b.second << "\n";
    MyPair<MyPair<string, int>, MyPair<string, int>> c(a, b);
    cout << c.first.first << ":" << c.first.second << "\n";
    cout << c.second.first << ":" << c.second.second << "\n";

    typedef MyPair<string, int> pair_t;
    pair_t d("chandrashekar", 180);
    cout << d.first << ":" << d.second << "\n";

    using jodi_t = MyPair<string, int>;
    jodi_t e("kapildev", 175);
    cout << e.first << ":" << e.second << "\n";

    using double_jodi_t = MyPair<jodi_t, jodi_t>;
    double_jodi_t f(a, b);
    cout << f.first.first << ":" << f.first.second << "\n";
    cout << f.second.first << ":" << f.second.second << "\n";

    p<string, int> g("ramanujan", 1729);
    cout << g.first << ":" << g.second << "\n";

    auto h = 10;
    cout << h << "\n";

    auto x = MyPair<int, int>(6, 28);
    cout << x.first << ":" << x.second << "\n";

    auto y = make_MyPair(7, 11);
    cout << y.first << ":" << y.second << "\n";
}
#if 0
template<typename T1, typename T2>
MyPair<T1, T2> make_MyPair(T1 first, T2 second)
{
	return MyPair<T1, T2>(first, second);
}
#endif
