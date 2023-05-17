#include <iostream>

class Add {
public:
    int operator()(int a, int b) const {
        return a + b;
    }
};

int main() {
    int x = 5;
    int y = 2;
    double z = 2.5;

    Add adder;
    int result1 = adder(x, y);  // ok, both arguments are ints
    int result2 = adder(x, z);  // error: no matching function for call to 'Add::operator()(int&, double&)'

    std::cout << "Result1: " << result1 << std::endl;
    std::cout << "Result2: " << result2 << std::endl;

    return 0;
}
