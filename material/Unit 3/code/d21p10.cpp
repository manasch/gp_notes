#include <iostream>
#include <vector>
#include <array>

int main() {
    // No out of bounds checking
    std::vector<int> v {1, 2, 3};
    //int x = v[10]; // Undefined behavior, may crash
    int z = v.at(10); // Throws std::out_of_range exception

    // No iterator safety
    std::vector<int> v1 {1, 2, 3};
    auto it = v1.begin();
    v1.push_back(4); // Invalidates iterator 'it'
    if (it == v1.begin()) {
        std::cout << "They are the same\n";
    } else {
        std::cout << "Not the same\n";
    }

    // No initialization
    std::vector<int> v2(10); // Creates a vector with 10 uninitialized elements
    std::array<int, 10> a; // Creates an array with 10 default-initialized elements

    // No type safety
    std::vector<int> v3 {1, 2, 3};
    v3.push_back(9.9);
    std::cout << v3[3] << "\n";

    // No performance guarantee
    std::vector<int> v4 {1, 2, 3, 4};
    auto it2 = v4.begin();
    std::advance(it2, 2); // O(n) operation, may be slow for large vectors
    int y = *it2; // O(1) operation, fast

    return 0;
}
