#include <iostream>
using namespace std;

template <class T> void print(const T &arg) { cout << "arg : " << arg << "\n"; }
// redefinition error
template <class T> void print(const T &arg) { arg.disp(); }

class A
{
  public:
    void disp() const { cout << "A displayed\n"; }
};
int main()
{
    int a(10);
    string b("ten");
    print(a);
    print(b);

    A x;
    print(x);
}
