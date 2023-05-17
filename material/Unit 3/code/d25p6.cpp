#include <iostream>
#include <vector>
#include <chrono>

int main() {
    //TODO  Create a vector of integers
    std::vector<int> vec;

    //TODO Measure the time taken to add 1000000 elements to the vector
    auto start = std::chrono::high_resolution_clock::now();

    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken with default constructor: " << elapsed.count() << " ms" << std::endl;

    //* Clear the vector
    //* example like vec.clear();

    
    // TODO do some magic Measure the time taken to add 1000000 elements to the vector
    start = std::chrono::high_resolution_clock::now();
    //TODO Choo mantar, gele gele here
    
    //TODO repeat the same for loop

    end = std::chrono::high_resolution_clock::now();

    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken with reserve(): " << elapsed.count() << " ms" << std::endl;

    return 0;
}
