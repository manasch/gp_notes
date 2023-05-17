#include<iostream>
template <typename T>
struct base_parser
{
   template <typename U>
   struct token {};
};
template <typename T>
struct parser : base_parser<T>
{
   void parse()
   {
      // todo I want create a class token
      // todo but that guy is a template 
      // todo I want a type of token so
      // !put typename infront of it 
      using token_type = 
      typename base_parser<T>::template token<int>; // [1]
      token_type t1{};
      typename base_parser<T>::template token<int> t2{}; 
                                                     // [2]
      std::cout << "parse\n";
   }
};
int main()
{
    parser<double> p;
    p.parse();
    return 0;
}
