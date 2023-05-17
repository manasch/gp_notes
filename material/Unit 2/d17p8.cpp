#include<iostream>
template <typename T>
struct base_parser {
  //! Here value_type is a type
  //! manne - everytime you see value_type-> T
  //!and value that T takes is passed thru 
  //!template arguments - ALIAS urf Razor Seena/ Kobri Manja
  using value_type = T;
};

template <typename T>
struct parser : base_parser<T> {
  void parse() {
    //! value_type v{};                  
    //* [1] error value_type is a non-dependendent name
    //* It does not work here because it does 
    //* know it is a typename as starts acting on 
    //* the less than symbol
    //! base_parser<T>::value_type v{};      
    //! [2] error

    // todo To correct this tell the compiler that
    // todo base_parser<T>::value_type is a typename
    // todo then all is well
    // todo artha iyetha bro ?
    typename base_parser<T>::value_type v{};
    std::cout << "parse\n";
  }
};

int main() {
  parser<int> p;
  p.parse();
  return 0;
}
