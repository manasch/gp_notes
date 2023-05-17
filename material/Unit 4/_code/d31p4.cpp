#include <iostream>
#include <type_traits>
#include<typeinfo>

template<int n>
struct F {
    static constexpr int value = n * 2;
};

template<int n>
struct G {
    static constexpr int value = n / 2;
};

template<int q>
using K = std::conditional_t<(q < 0), int, unsigned>;

template<int q>
using D = std::conditional_t<(q < 0), F<q>, G<q>>;

int main() {
    constexpr int q1 = 10;
    constexpr int q2 = -10;
    
    // declare k to have 1 of these 2 integer types
    K<q1> k1; // unsigned
    K<q2> k2; // int
    
    std::cout << k1 << std::endl; // Output:  unsigned
    std::cout << k2 << std::endl; // Output: int
    
    // instantiate and call 1 of these 2 function objects
    D<q1>::value; // F<q1>::value = 20
    D<q2>::value; // G<q2>::value = -5
    
    // inherit from 1 of these 2 base classes
    class C : public D<q1> {}; // inherits from F<q1>
    class E : public D<q2> {}; // inherits from G<q2>
    
    return 0;
}
