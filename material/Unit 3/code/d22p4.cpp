#include <iostream>
#include <vector>

int main() {
    // Create two vectors with some values
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    // Get the maximum size of the vectors
    std::cout << "Maximum size of vec1: " << vec1.max_size() << std::endl;
    std::cout << "Maximum size of vec2: " << vec2.max_size() << std::endl;
    std::cout << "size of vec1" << vec1.size() << std::endl;
    // Swap the contents of the vectors
    std::cout << "Before swap:" << std::endl;
    std::cout << "vec1: ";
    for (int i : vec1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "vec2: ";
    for (int i : vec2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    vec1.swap(vec2);

    std::cout << "After swap:" << std::endl;
    std::cout << "vec1: ";
    for (int i : vec1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "vec2: ";
    for (int i : vec2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Compare the contents of the vectors for equality
    if (vec1 == vec2) {
        std::cout << "vec1 and vec2 are equal" << std::endl;
    } else {
        std::cout << "vec1 and vec2 are not equal" << std::endl;
    }

    return 0;
}
