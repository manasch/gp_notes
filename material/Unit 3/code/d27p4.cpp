template <typename T>
struct identity {
    using type = T;
};
#include <type_traits>
#include <iostream>

template <typename T>
void foo(typename identity<T>::type x) {
    std::cout << "foo called with value " << x << " of type " << typeid(x).name() << std::endl;
}

int main() {
    foo<int>(42);
    foo<double>(3.14);

    return 0;
}
