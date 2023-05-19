#include <iostream>
using namespace std;
#include <concepts>

template <typename T> concept myconcept1 = is_default_constructible<T>::value;

template <typename T> requires myconcept1<T> class A
{
  public:
    A() { cout << "ctor of A\n"; }
};
class ZZZ
{
  public:
    ZZZ(int) {}

  private:
    ZZZ() {}
};
int main()
{
    A<bool> x;
    A<ZZZ> y;
}
