#include <iostream>
using namespace std;
#include <concepts>
template <typename T> struct Trait
{
    static const bool value = true;
};
template <> struct Trait<int>
{
    static const bool value = false;
};

template <typename T> concept myconcept = Trait<T>::value;

template <typename T> requires myconcept<T> class A
{
  public:
    A() { cout << "ctor of A\n"; }
};

class ZZZ
{
  public:
    ZZZ(int) {}
    // private:
    ZZZ();
};
int main()
{
    A<bool> x;
    A<ZZZ> y;
    // A<int> z;
}
