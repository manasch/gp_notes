#include<iostream>
template <typename T>
struct processor;       
//* [1] template declaration
void handle(double value)  
//* [2] handle(double) definition
{
   std::cout << "processing a double: " << value << '\n';
}
void handle(int value)    
 //* [5] handle(int) definition
{
   std::cout << "processing an int: " << value << '\n';
}
template <typename T>
struct parser              
//* [3] template definition
{
   void parse()
   {
      handle(42);          
      //! [4] non-dependent name
   }
};

int main()
{
   parser<int> p;          
   // TODO [6] template instantiation
   p.parse();
}