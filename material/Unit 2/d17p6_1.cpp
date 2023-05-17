#include<iostream>
// I have a base template
template<typename T>
struct base_parser
{
  inline void init()
  {
    std::operator<<(std::cout, "init\n");
  }
  
};

/* First instantiated from: insights.cpp:22 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct base_parser<double>
{
  inline void init()
  {
    std::operator<<(std::cout, "init\n");
  }
  
  // inline constexpr base_parser() noexcept = default;
};

#endif

// I have specialized this template
template<>
struct base_parser<int>
{
  inline void init()
  {
    std::operator<<(std::cout, "specialized init\n");
  }
  
  // inline constexpr base_parser() noexcept = default;
};


// a a derived class based on base_parser
template<typename T>
struct parser : public base_parser<T>
{
  inline void parse()
  {
    base_parser<T>::init();
    std::operator<<(std::cout, "parse\n");
  }
  
};

/* First instantiated from: insights.cpp:35 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct parser<int> : public base_parser<int>
{
  inline void parse()
  {
    /* static_cast<base_parser<int> *>(this)-> */ init();
    std::operator<<(std::cout, "parse\n");
  }
  
  // inline constexpr parser() noexcept = default;
};

#endif
/* First instantiated from: insights.cpp:37 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct parser<double> : public base_parser<double>
{
  inline void parse()
  {
    /* static_cast<base_parser<double> *>(this)-> */ init();
    std::operator<<(std::cout, "parse\n");
  }
  
  // inline constexpr parser() noexcept = default;
};

#endif



int main()
{
  parser<int> p1 = parser<int>();
  p1.parse();
  parser<double> p2 = parser<double>();
  p2.parse();
  return 0;
}
