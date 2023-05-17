//#define CLASS
#ifdef CLASS
#include <iostream>
#define DECLARE_CLASS(name) \
class MyClass_##name { \
public: \
    void sayHello() { std::cout << "Hello from MyClass_" << #name << std::endl; } \
};

DECLARE_CLASS(Foo)
DECLARE_CLASS(Bar)
DECLARE_CLASS(Baz)

int main() {
    MyClass_Foo foo;
    MyClass_Bar bar;
    MyClass_Baz baz;

    foo.sayHello();
    bar.sayHello();
    baz.sayHello();

    return 0;
}
#endif

#define VAR
#ifdef VAR
#include <iostream>

#define CONCAT(x, y) x##y

int main() {
    int myVar_1 = 42;
    int CONCAT(myVar_, 2) = 84;

    std::cout << "myVar_1 = " << myVar_1 << std::endl;
    std::cout << "myVar_2 = " << myVar_2 << std::endl;

    return 0;
}

#endif
