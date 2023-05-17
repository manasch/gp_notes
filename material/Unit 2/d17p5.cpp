#include<iostream>
template <typename T>
struct base_parser
{
   void init()
   {
      std::cout << "init\n";
   }
};
// ! Derived from base parser
template <typename T>
struct parser : base_parser<T>
{
   void parse()
   {  // *init does not depend on type and 
      // *base_parser has not been instantiated
      // *so the top code here is as good
      // *as comment here
      //!init();  error: identifier not found
      this->init(); // todo  will work
      base_parser<T>::init(); // todo will also work
      // !both these make init a dependent name
      std::cout << "parse\n";
   }
};
int main()
{
   parser<int> p;
   p.parse();
   // !Try specializing the  base parser  above/below and see what happens
}

