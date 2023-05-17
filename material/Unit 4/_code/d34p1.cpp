#include <iostream>
#include <type_traits>

template <typename T>
constexpr T compute(T const a, T const b)
{
    if constexpr (std::is_integral_v<T>)
        return a * b;
    else
        return a + b;
}

int main()
{
    constexpr int a = 3;
    constexpr int b = 4;
    constexpr auto result = compute(a, b);

    static_assert(result == 12);
    std::cout << "Result: " << result << std::endl;

    constexpr double x = 2.5;
    constexpr double y = 1.5;
    constexpr auto result2 = compute(x, y);

    static_assert(result2 == 4.0);
    std::cout << "Result2: " << result2 << std::endl;

    return 0;
}
