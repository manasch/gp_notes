#include <iostream>
#include <type_traits>

template <typename T>
struct identity {
    using type = T;
};

template <typename T>
struct add_pointer : identity<T*> {};

template <typename T>
struct add_reference : identity<T&> {};

template <typename T>
struct remove_reference : identity<T> {};

template <typename T>
struct remove_reference<T&> : identity<T> {};

int main() {
    std::cout << std::is_same<int*, add_pointer<int>::type>::value << std::endl; // true
    std::cout << std::is_same<int&, add_reference<int>::type>::value << std::endl; // true
    std::cout << std::is_same<int, remove_reference<int&>::type>::value << std::endl; // true
    std::cout << std::is_same<int, remove_reference<int>::type>::value << std::endl; // true

    return 0;
}
