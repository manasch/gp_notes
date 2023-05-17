#include <iostream>

// Try making Inner private and then accessing
// Try accessing inner private members from outer

class OuterClass {
private:
    class InnerClass {
    public:
        int innerValue;
        void displayValue() {
            std::cout << "Inner Value: " << innerValue << std::endl;
        }
    };

public:
    InnerClass innerObject;
};

int main() {
    OuterClass outerObject;
    outerObject.innerObject.innerValue = 10;
    outerObject.innerObject.displayValue();
    return 0;
}
