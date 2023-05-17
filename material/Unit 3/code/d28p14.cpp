#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    // Define a vector with 10 elements
    std::vector<int> v(10);

    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);

    // Use generate to fill the vector with random integers
    std::generate(v.begin(), v.end(), [&]() {
        return dis(gen);
    });

    // Print the contents of the vector
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
