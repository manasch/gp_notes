#include <iostream>
using namespace std;

int main()
{
    // lambda functions : functions with no name
    //
    []() {}(); // [] : capture ; () : parameter; { } : body ; () : call
    []() { cout << "hello world\n"; }();
    auto f1 = []() { cout << "hello world\n"; };
    f1();
    // int a; int b; a = ...; b = ...; int c = a + b; foo(c);
    // or
    // int a; int b; a = ...; b = ...;  foo(a + b);
    // use lambda function as an argument to a function
    // replacement for a named callable

    auto f2 = [](int x, int y) { return x + y; };
    cout << f2(3, 4) << "\n";
    cout << f2(31, 42) << "\n";

    auto f3 = [](int x, int y) -> int { return x + y; };
    cout << f3(3, 4) << "\n";
    cout << f3(31, 42) << "\n";

    // global variables are visible in lambda
    // local variables are not visible by default
    int n = 10;
    auto f4 = [n](int x, int y) -> int { return x + y + n; };
    // n : rvalue only
    cout << f4(3, 4) << "\n";
    cout << f4(31, 42) << "\n";

    // n : lvalue
    auto f5 = [&n](int x, int y) -> int {
        n = 20;
        return x + y + n;
    };
    cout << f5(3, 4) << "\n";
    cout << f5(31, 42) << "\n";
    cout << "n : " << n << "\n";

    int m;
    n = 100;
    m = 200;
    //	auto f6 = [&n, m]()  { n += m;   };
    auto f6 = [&]() { n += m; };
    f6();
    cout << "n : " << n << "\t"
         << " m : " << m << "\n";

    auto f7 = [=]() { cout << n * m << "\n"; };
    f7();
}
