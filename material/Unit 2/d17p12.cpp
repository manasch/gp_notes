#include <iostream>
template <typename T> 
class A {
    A* p1;      // A is the current instantiation
    A<T>* p2;   // A<T> is the current instantiation
    ::A<T>* p4; // ::A<T> is the current instantiation
    A<T*> p3;   // A<T*> is not the current instantiation
};

template <typename T> 
class A<T*> {
    A<T*>* p1;  // A<T*> is the current instantiation
    A<T>* p2;   // A<T> is not the current instantiation
};

template <int I> 
struct B {
    static const int my_I = I;
    static const int my_I2 = I + 0;
    static const int my_I3 = my_I;
    B<my_I>* b3;  // B<my_I> is the current instantiation
    B<my_I2>* b4; // B<my_I2> is not the current instantiation
    B<my_I3>* b5; // B<my_I3> is the current instantiation
};

int main() {
    A<int> a1;
    A<int*> a2;
    B<10> b1;
    std::cout << "Instantiation of A<int> is successful." << std::endl;
    std::cout << "Instantiation of A<int*> is successful." << std::endl;
    std::cout << "Instantiation of B<10> is successful." << std::endl;
    return 0;
}
