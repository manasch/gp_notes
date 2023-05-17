#include <iostream>

class MyFunctor {
public:
    MyFunctor(int x) : value_(x) {}

    //* Only function present
    int operator()(int x) {
        return x * value_;
    }

private:
    int value_;
};

int main() {
    MyFunctor f(5); //* Constructor
    //* Operator call
    int result = f(10);
    std::cout << result << std::endl; // output: 50
    return 0;
}
