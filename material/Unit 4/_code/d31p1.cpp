#include<iostream>
#include<typeinfo>
template <typename T, std::size_t N>
struct ArraySize {
    static constexpr std::size_t value = N;
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Size of arr: " 
    << ArraySize<decltype(arr)
    , sizeof(arr)>::value << std::endl; 
    //* Output: Size of arr: 20
    return 0;
}
//#define COMMENT
#ifdef COMMENT
int foo();
int n = 10;
decltype(n) a = 20;            
//* a is an "int" [id-expression]
decltype((n)) b = a;           
//* b is an "int &" [(n) is an lvalue]
decltype(foo()) c = foo();      
//* c is an "int" [rvalue]
#endif