#include<iostream>
using namespace std;
struct wrapper
{
   wrapper(int const v) :value(v) {}
private:
   int value;
   // Have declared 2 friends of type template
   template <typename T>
   friend void print(wrapper const&);
   template <typename T>
   friend struct printer;
};   
template <typename T>
void print(wrapper const& w)
{ std::cout << w.value << '\n'; }
template <typename T>
struct printer
{
   void operator()(wrapper const& w)
   { std::cout << w.value << '\n'; }
};
int main()
{
wrapper w{ 42 };
print<int>(w);
print<char>(w);
printer<int>()(w);
printer<double>()(w);
}

