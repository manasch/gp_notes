#include<map>
#include<iostream>
struct dictionary_traits
{
    using key_type = int;
    using map_type = std::map<key_type, std::string>;
    static constexpr int identity = 1;
};
template <typename T> //* T is a type of type class
struct dictionary :T::map_type      //! Funny I dont need it here [1]
{
    int start_key { T::identity };   //! Nothing special here [2]
    typename T::key_type next_key;   //! Back to my old tricks  [3]
};
int main()
{
    dictionary<dictionary_traits> d;
}