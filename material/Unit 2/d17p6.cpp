#include<iostream>
// ! I have a base template
template <typename T>
struct base_parser
{
   void init()
   {
      std::cout << "init\n";
   }
};
//! I have specialized this template
template <>
struct base_parser<int>
{
   void init()
   {
      std::cout << "specialized init\n";
   }
};
// * a derived class based on base_parser
template <typename T>
struct parser : base_parser<T>
{
   void parse()
   {  
      
      base_parser<T>::init(); 
      std::cout << "parse\n";
   }
};


int main()
{
   parser<int> p1;
   p1.parse();
   parser<double> p2;
   p2.parse();
}