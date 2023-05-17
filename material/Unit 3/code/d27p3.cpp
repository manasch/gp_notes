#include <type_traits>

template <typename T>
struct is_floating_point {
    static constexpr bool value =
     std::is_same<T, float>::value 
     || std::is_same<T, double>::value;
};

int main() {
    static_assert(is_floating_point<float>::value);
    static_assert(is_floating_point<double>::value);
    static_assert(!is_floating_point<int>::value);

    return 0;
}
