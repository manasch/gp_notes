#include<map>
#include<iostream>
struct dictionary_traits
{
  using key_type = int;
  using map_type = std::map<key_type, std::basic_string<char, std::char_traits<char>, std::allocator<char> > >;
  inline static constexpr const int identity = 1;
};


template<typename T>
struct dictionary : public T::map_type
{
  int start_key{T::identity};
  typename T::key_type next_key;
};

/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
struct dictionary<dictionary_traits> : public std::map<int, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<int>, std::allocator<std::pair<const int, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >
{
  int start_key{dictionary_traits::identity};
  typename dictionary_traits::key_type next_key;
  // inline ~dictionary() noexcept = default;
  // inline dictionary() noexcept = default;
};

#endif

int main()
{
  dictionary<dictionary_traits> d = dictionary<dictionary_traits>();
  return 0;
}
