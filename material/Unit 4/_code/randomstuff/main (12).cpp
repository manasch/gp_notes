#include <iostream>
#include <type_traits>

// Define tag types for different operations
struct AddTag {};
struct SubtractTag {};

// Primary template for a function that takes two arguments
template<typename T, typename U>
T arithmetic(T a, U b, AddTag) {
    std::cout << "Adding..." << std::endl;
    return a + b;
}

// Specialization of the above template for subtracting
template<typename T, typename U>
T arithmetic(T a, U b, SubtractTag) {
    std::cout << "Subtracting..." << std::endl;
    return a - b;
}

// A function that determines which tag to use based on a boolean condition
template<typename T, typename U>
T arithmetic(T a, U b, bool add) {
    if (add) {
        return arithmetic(a, b, AddTag{});
    }
    else {
        return arithmetic(a, b, SubtractTag{});
    }
}

int main() {
    std::cout << arithmetic(5, 3, true) << std::endl; // Output: Adding... 8
    std::cout << arithmetic(5, 3, false) << std::endl; // Output: Subtracting... 2
    return 0;
}
