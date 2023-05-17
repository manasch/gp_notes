#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Using a function object
class AddOne {
public:
    template <typename T>
    void operator()(T& t) const {
        t += 1;
    }
};

// Using an ordinary function
template <typename T>
void addOne(T& t) {
    t += 1;
}

int main() {
    std::vector<int> intVec(100000000, 0);

    auto start1 = std::chrono::high_resolution_clock::now();
    std::for_each(intVec.begin(), intVec.end(), AddOne{});
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    std::for_each(intVec.begin(), intVec.end(), addOne<int>);
    auto end2 = std::chrono::high_resolution_clock::now();

    std::cout << "Using a function object: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << " ms" << std::endl;
    std::cout << "Using an ordinary function: " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << " ms" << std::endl;

    return 0;
}
