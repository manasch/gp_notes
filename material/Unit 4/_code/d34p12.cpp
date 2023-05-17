//#define BASE
#ifdef BASE
#include <iostream>
#include <type_traits>

class NotPolymorphic {
public:
    void doSomething() {}
};

class Polymorphic {
public:
    virtual void doSomething() {}
};

int main() {
    constexpr bool is_not_polymorphic_polymorphic = std::is_polymorphic<NotPolymorphic>::value;
    constexpr bool is_polymorphic_polymorphic = std::is_polymorphic<Polymorphic>::value;

    std::cout << std::boolalpha;
    std::cout << "Is NotPolymorphic polymorphic? " << is_not_polymorphic_polymorphic << std::endl;
    std::cout << "Is Polymorphic polymorphic? " << is_polymorphic_polymorphic << std::endl;

    return 0;
}
#endif
#define DERIVED
#ifdef DERIVED
#include <iostream>
#include <type_traits>

class NotPolymorphic {
public:
    void doSomething() {}
};

class Derived : public NotPolymorphic {
public:
    void doSomething() {const int i = 0;}
};

int main() {
    constexpr bool is_not_polymorphic_polymorphic = std::is_polymorphic<NotPolymorphic>::value;
    constexpr bool is_derived_polymorphic = std::is_polymorphic<Derived>::value;

    std::cout << std::boolalpha;
    std::cout << "Is NotPolymorphic polymorphic? " << is_not_polymorphic_polymorphic << std::endl;
    std::cout << "Is Derived polymorphic? " << is_derived_polymorphic << std::endl;

    return 0;
}

#endif
