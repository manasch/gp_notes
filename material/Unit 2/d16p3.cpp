// Inner class can access outer class
//  variable as well
// d16p3.cpp
// Now make outervalue private and see if you can
// access it
#include <iostream>

class OuterClass {
public:
    int outerValue;

    class InnerClass {
    public:
        int innerValue;
        void displayOuterValue(const OuterClass &outer) {
            std::cout << "Outer Value: " << outer.outerValue << std::endl;
        }
    };

    InnerClass innerObject;
};

int main() {
    OuterClass outerObject;
    outerObject.outerValue = 10;
    outerObject.innerObject.innerValue = 20;
    outerObject.innerObject.displayOuterValue(outerObject);
    return 0;
}
