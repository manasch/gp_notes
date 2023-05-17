#include <type_traits>
#include <iostream>
template <typename T>
void destroy_object(T& obj) {
    if constexpr (std::
    is_trivially_destructible_v<T>) {
        std::cout << "Object is trivially destructible, no action needed.\n";
    } else {
        std::cout << "Calling destructor of the object.\n";
        obj.~T();
    }
}

class NonTrivial {
public:
    NonTrivial() { std::cout << "Constructing NonTrivial object.\n"; }
    ~NonTrivial() { std::cout << "Destructing NonTrivial object.\n"; }
};

int main() {
    int i = 5;
    destroy_object(i);

    NonTrivial nt;
    destroy_object(nt);

    return 0;
}
