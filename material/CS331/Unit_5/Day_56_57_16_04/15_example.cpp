#include <iostream>
using namespace std;
class A;

template <class T>
typename enable_if<!is_same<T, A>::value>::type print(const T &arg)
{
    cout << "arg : " << arg << "\n";
}

template <class T>
typename enable_if<is_same<T, A>::value>::type print(const T &arg)
{
    arg.disp();
}

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
