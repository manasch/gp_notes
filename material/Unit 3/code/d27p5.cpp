#include <iostream>
#include <type_traits>

template <typename T>
void foo(T x) {
    using U = std::remove_reference_t<T>;
    std::cout << "foo called with type "
     << typeid(U).name() << std::endl;
}

int main() {
    int x = 42;
    int& y = x;

    foo(x);
    foo(y);

    return 0;
}
//#define RANK
#ifdef RANK
#include <iostream>
#include <type_traits>

template <typename T>
void foo(T x) {
    using U = std::remove_reference_t<T>;
    std::cout << "foo called with type " << typeid(U).name() << std::endl;

    std::cout << "rank of T is " << std::rank<T>::value << std::endl;
    std::cout << "rank of U is " << std::rank<U>::value << std::endl;
}

int main() {
    int arr[3][4];
    foo(arr);

    return 0;
}

#endif
