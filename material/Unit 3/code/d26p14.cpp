#include <iostream>
#include <vector>

class Functor {
public:
    virtual int operator()(int) = 0;
};

class Double : public Functor {
public:
    int operator()(int x) override {
        return 2 * x;
    }
};

class Square : public Functor {
public:
    int operator()(int x) override {
        return x * x;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    
    Functor* f = new Double;
    for (auto num : nums) {
        std::cout << (*f)(num) << " ";
    }
    std::cout << std::endl;
    
    delete f;
    
    f = new Square;
    for (auto num : nums) {
        std::cout << (*f)(num) << " ";
    }
    std::cout << std::endl;
    
    delete f;
    return 0;
}
