#include <type_traits>
#include<iostream>
int main() {
    bool is_int = std::is_same<int, decltype(42)>::value;
    std::cout << std::boolalpha << is_int << std::endl;
}
// Compile Time, Run Time , Error, compile time if changed to sizeof
