#include <iostream>
#include <string>

// This program demonstrates how to use the __LINE__ macro
// to generate unique variable names at compile time.

#define UNIQUE_NAME(base) (base##__LINE__)

int main() {
    int UNIQUE_NAME(x) = 10;
    int UNIQUE_NAME(y) = 20;
    
    std::cout << "x = " << UNIQUE_NAME(x) << std::endl;
    std::cout << "y = " << UNIQUE_NAME(y) << std::endl;
    
    int UNIQUE_NAME(z) = 30;
    std::cout << "z = " << UNIQUE_NAME(z) << std::endl;
    
    return 0;
}
