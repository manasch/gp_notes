#include <iostream>
using namespace std;
#include <concepts>

class A
{
  public:
    void foo() const { cout << "this is a test\n"; }
};

class B
{
};

template <typename T> concept HasFoo = requires(const T &a) { a.foo(); };

template <typename T> requires HasFoo<T> void call(const T &x) { x.foo(); }

int main()
{
    A a;
    call(a);
    B b;
    call(b);
}
