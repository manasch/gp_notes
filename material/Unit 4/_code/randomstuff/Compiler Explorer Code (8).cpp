#include <iostream>
#include <type_traits>

template<typename T>
struct has_addition_operator
{
    template<typename U, typename V>
    static auto test(U* u, V* v) -> decltype(*u + *v);

    template<typename, typename>
    static void test(...);

    constexpr static bool value = !std::is_void<decltype(test<T,T>(nullptr, nullptr))>::value;
};

template<typename T>
typename std::enable_if<has_addition_operator<T>::value, T>::type add(T a, T b)
{
    return a + b;
}

int main()
{
    int x = 3, y = 4;
    double z = 5.6;
    auto ans = add(x,y);
    std::cout << add(x, y) << std::endl;
    // std::cout << add(x, z) << std::endl; // error: no match for 'operator+' (operand types are 'int' and 'double')
    return 0;
}
