#include <iostream>
class Incrementer {
public:
    Incrementer(int start) :
                       count_(start) {}
    int operator()() {
        return count_++;
    }

private:
    int count_;
};

int main() {
    Incrementer inc(0);
    std::cout << inc() << std::endl; 
    //* output: 0
    std::cout << inc() << std::endl; 
    //* output: 1
    std::cout << inc() << std::endl; 
    //* output: 2
    return 0;
}
