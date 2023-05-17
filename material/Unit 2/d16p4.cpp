#include <iostream>
#include <vector>

// I can have a vector of inner classes as well
// see line 19

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

    std::vector<InnerClass> innerVector;
};

int main() {
    OuterClass outerObject;
    outerObject.outerValue = 10;
    outerObject.innerVector.push_back({0});
    outerObject.innerVector.push_back({1});
    outerObject.innerVector.push_back({2});
    return 0;
}
