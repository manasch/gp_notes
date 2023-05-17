#include <iostream>
#include <vector>
#include <chrono>

int main() {
    // Create a vector of integers
    std::vector<int> vec;

    // Measure the time taken to add 1000 elements to the vector
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++) {
        vec.push_back(i);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken with default constructor: " << elapsed.count() << " ms" << std::endl;

    // Clear the vector
    vec.clear();

    // Reserve space for 1000 elements
    vec.reserve(10000000);

    // Measure the time taken to add 1000 elements to the vector
    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++) {
        vec.push_back(i);
    }

    end = std::chrono::high_resolution_clock::now();

    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken with reserve(): " << elapsed.count() << " ms" << std::endl;

    return 0;
}
