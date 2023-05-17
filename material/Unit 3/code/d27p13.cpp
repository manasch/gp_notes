#include<iostream>
#include<type_traits>
template<bool B, typename T>
struct enable_if {};
 
template<typename T>
struct enable_if<true, T> {
     typedef T type; };

template<typename T>
typename enable_if<std::is_integral<T>::value, T>::type 
foo(T t) {
    std::cout << "T is integral" << std::endl;
    return t;
};
template<typename T>
void f(typename enable_if<std::is_integral<T>::value, T>::type t) {
    std::cout << "T is integral" << std::endl;
};
int main()
{
    foo(1);
   //! foo("string");
}