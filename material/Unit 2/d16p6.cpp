#include <iostream>
// Does this work
// Explain this to me
// Do this inners have a life oustide of outer

class Outer {
public:
    class Inner1 {
    public:
        int value1;
        void printValue1() {
            std::cout << "Value1: " << value1 << std::endl;
        }
    };

    class Inner2 {
    public:
        int value2;
        void printValue2() {
            std::cout << "Value2: " << value2 << std::endl;
        }
    };
};

int main() {
    // Outer obj;
    Outer::Inner1 inner1;
    inner1.value1 = 42;
    inner1.printValue1();

    Outer::Inner2 inner2;
    inner2.value2 = 99;
    inner2.printValue2();

    return 0;
}
