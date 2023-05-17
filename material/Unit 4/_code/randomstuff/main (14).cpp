#include <iostream>
#include <type_traits>

template <typename T, bool IS_SMALL_OBJ = (sizeof(T) < sizeof(void*))>
class A {
public:
    A() {
        std::cout << "A() called with T = " << typeid(T).name() << std::endl;
    }
};

template <typename T>
class A<T, true> {
public:
    A() {
        std::cout << "A() called with small T = " << typeid(T).name() << std::endl;
    }
};

template <typename T>
class A<T, false> {
public:
    A() {
        std::cout << "A() called with large T = " << typeid(T).name() << std::endl;
    }
};

int main() {
    A<int> a1; // calls A<int, true> specialization
    A<long long> a2; // calls A<long long, false> specialization
    A<double, true> a3; // calls A<double, true> specialization
    A<char[10]> a4; // calls A<char[10], true> specialization

    return 0;
}