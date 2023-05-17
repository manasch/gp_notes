#include <iostream>

template<typename... Args>
void my_function(Args... args) {
    std::cout << "Number of arguments: " << sizeof...(Args) << std::endl;
    std::cout << "Argument types: ";
    ((std::cout << typeid(Args).name() << " "), ...);
    std::cout << std::endl;
    std::cout << "Arguments: ";
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

int main() {
    int a = 1;
    double b = 2.5;
    const char* c = "hello";
    char d = 'c';

    my_function(a, b, c, d);

    return 0;
}
