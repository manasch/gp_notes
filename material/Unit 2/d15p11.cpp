#include<iostream>
template <typename T>
// if we need to give access only to
// a certain instance of wrapper
struct wrapper
{
   wrapper(T const v) :value(v) {}
private:
   T value;
   // only wrapper<int> available to printcl
   friend void print(wrapper<int> const&);
};
void print(wrapper<int> const& w)
{ std::cout << w.value << '\n'; }

// void print(wrapper<char> const& w)
// { std::cout << w.value << '\n';  }
int main()
{
    
}