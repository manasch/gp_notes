#include <iostream>
#include <type_traits>
#define DEST
#ifdef DEST

struct A {
    A(const A&) = delete;
    ~A() noexcept(false) {}
};

struct B {
    B(const B&) = delete;
    ~B() noexcept {}
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "A is destructible: "
     << std::is_destructible<A>::value << std::endl;
    std::cout << "A is nothrow destructible: "
     << std::is_nothrow_destructible<A>::value << std::endl;

    std::cout << "B is destructible: " << std::is_destructible<B>::value << std::endl;
    std::cout << "B is nothrow destructible: " << std::is_nothrow_destructible<B>::value << std::endl;

    return 0;
}

#endif
#define COPY
#ifdef COPY
#include <iostream>
#include <type_traits>

class A {
public:
    A() {}
    A(const A&) { std::cout << "Copy constructor called" << std::endl; }
};

class B {
public:
    B() {}
    B(const B&) = delete;
};

int main() {
    std::cout << std::boolalpha;

    std::cout << "A is copy-constructible: " 
    << std::is_copy_constructible<A>::value << std::endl;
    std::cout << "B is copy-constructible: " 
    << std::is_copy_constructible<B>::value << std::endl;

    return 0;
}


#endif
