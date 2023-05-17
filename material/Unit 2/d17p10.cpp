// *There are cases where dependent name is a function
// *template or a class template
#include<iostream>

template <typename T>
struct base_parser
{
   template <typename U>
   void init()
   {
      std::cout << "init\n";
   }
};
template <typename T>
struct parser : base_parser<T>
{
   void parse()
   {
    // !d17p6 init was not a template 
    // !here init is also a template
    // !I must tell the compiler that this is a
    // !template
    // *  base_parser<T>::init<int>();        
    // * [1] error
    // todo I must prefix template infront of init
      base_parser<T>::template init<int>();  // [2] OK
      std::cout << "parse\n";
   }
};
   int main()
{
    parser<double> p;
    p.parse();
    return 0;
}