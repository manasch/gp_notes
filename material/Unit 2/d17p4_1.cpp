// ! cppinsights file of d17p4.cpp
#include<iostream>
template<typename T>
struct handler
{
  inline void handle(T value)
  {
    (std::operator<<(std::cout, "handler<T>: ") << value) << '\n';
  }
  
};


template<typename T>
struct parser
{
  inline void parse(T arg)
  {
    arg.handle(42);
  }
  
};

/* First instantiated from: insights.cpp:37 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct parser<handler<int> >
{
  inline void parse(handler<int> arg)
  {
    arg.handle(42);
  }
  
  // inline constexpr parser() noexcept = default;
};

#endif

template<>
struct handler<int>
{
  inline void handle(int value)
  {
    std::operator<<(std::operator<<(std::cout, "handler<int>: ").operator<<(value), '\n');
  }
  
  // inline constexpr handler() noexcept = default;
  // inline constexpr handler(const handler<int> &) noexcept = default;
};


int main()
{
  handler<int> h = handler<int>();
  parser<handler<int> > p = parser<handler<int> >();
  p.parse(handler<int>(h));
  return 0;
}

