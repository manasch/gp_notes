#include <iostream>
#include <type_traits>

template<typename... Types>
constexpr bool AllTypesAreIntegral = (std::is_integral_v<Types> && ...);

int main() {
    std::cout << std::boolalpha;
    std::cout << "All types are integral: " << AllTypesAreIntegral<int, short, long> << std::endl;
    std::cout << "All types are integral: " << AllTypesAreIntegral<int, float, double> << std::endl;
    return 0;
}
