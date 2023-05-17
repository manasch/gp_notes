// inheritance.cpp

#include <iostream>

class Base{
private:
    void func(){                    // (1)
        std::cout << "func\n";
    }
};

class Derived: public Base{
public:
    void callBase(){
        func();                      // (2)
    }
};

int main(){

    std::cout << '\n';

    Derived derived;
    derived.callBase();              

    std::cout << '\n';

}