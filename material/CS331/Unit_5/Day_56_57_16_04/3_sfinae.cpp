// substitution failure is not an error : SFINAE

#include <iostream>
using namespace std;
class Bar
{
  public:
    using mytype = char;
};

template <typename T> typename T::mytype foo(T t)
{
    cout << "foo generic\n";
    return typename T::mytype();
}
#if 1
int foo(int)
{
    cout << "foo int\n";
    return 0;
}

#endif
int main()
{
    foo(Bar());
    foo(10);
}
