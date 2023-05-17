#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename F>
class AdaptableFunctor {
public:
    AdaptableFunctor(const F& f) : func(f) {}
    void operator()(int& x) const {
        std::cout << "Before: " << x << std::endl;
        func(x);
        std::cout << "After: " << x << std::endl;
    }
private:
    F func;
};

void increment(int& x) {
    ++x;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Using a simple function object
    std::for_each(v.begin(), v.end(), AdaptableFunctor<void (*)(int&)>(increment));

    // Using a lambda function
    std::for_each(v.begin(), v.end(), AdaptableFunctor<std::function<void(int&)>>(
        [](int& x){ x *= 2; }
    ));

    return 0;
}
