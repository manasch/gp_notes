// allows us to bind a few arguments to a function
// then call providing the rest

#include <iostream>
using namespace std;
#include <algorithm>
#include <functional>

#if 1
int sub(int x, int y) { return x - y; }
#endif
#if 0
int sub(int p, int q, int r)
{
	return p + q + r;
}
#endif

int main()
{

    cout << sub(10, 4) << "\n";
    auto f1 = bind(sub, 11, 3);
    cout << f1() << "\n";

    auto f2 = bind(sub, placeholders::_1, placeholders::_2);
    cout << f2(12, 2) << "\n";

    using namespace placeholders;
    auto f3 = bind(sub, 13, _1);
    cout << f3(2) << "\n"; // sub : 2 arg ; f3 : 1 arg
    // function which takes n arg; provide a few; get a new function which
    //	takes a few arg less than n : currying

    auto f4 = bind(sub, _2, _1);
    cout << f4(12, 2) << "\n";

    auto f5 = bind(f3, 12);
    cout << f5() << "\n";

    function<int(int, int)> f6 = bind(sub, _1, _2);
    cout << f6(10, 1) << "\n";

    function<int(int)> f7 = bind(sub, 100, _1);
    cout << f7(20) << "\n";
}
