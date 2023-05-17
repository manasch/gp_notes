// I can call a member function of a nested class as 
// well
#include <iostream>

class OuterClass {
public:
    int outerValue;

    class InnerClass {
    public:
        int innerValue;
        void displayValue() {
            std::cout << "Inner Value: " << innerValue << std::endl;
        }
    };

    InnerClass innerObject;
};

int main() {
    OuterClass outerObject;
    outerObject.outerValue = 10;
    outerObject.innerObject.innerValue = 20;
    outerObject.innerObject.displayValue();
    return 0;
}
