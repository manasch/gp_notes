// templateInheritance.cpp

#include <iostream>

template <typename T>
class Base{
public:
    void func(){                    // (1)
        std::cout << "func\n";
    }
};

template <typename T>
class Derived: public Base<T>{
public:
    void callBase(){
        func();                      // (2)
    }
};

int main(){

    std::cout << '\n';

    Derived<int> derived;
    derived.callBase();              

    std::cout << '\n';

}