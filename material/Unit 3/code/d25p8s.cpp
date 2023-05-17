#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>
//! vector 0.000001652
//! set    0.000000768
//! Size 
int main() {
    const int size = 100000; // number of elements in the data set

    // create a sorted vector of integers
    std::vector<int> vec;
    for (int i = 0; i < size; ++i) {
        vec.push_back(i);
    }

    // create a set of integers
    std::set<int> s;
    for (int i = 0; i < size; ++i) {
        s.insert(i);
    }

    // measure the time it takes to find an element in the sorted vector
    auto start_vec = std::chrono::high_resolution_clock::now();
    std::binary_search(vec.begin(), vec.end(), size - 1);
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_vec = end_vec - start_vec;

    // measure the time it takes to find an element in the set
    auto start_set = std::chrono::high_resolution_clock::now();
    s.find(size - 1);
    auto end_set = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_set = end_set - start_set;

    std::cout << "Time taken to find an element in a sorted vector: " << time_vec.count() << " seconds\n";
    std::cout << "Time taken to find an element in a set: " << time_set.count() << " seconds\n";

    // calculate the memory difference between the two data structures
    const int vec_size = vec.size() * sizeof(int);
    const int set_size = sizeof(s);
    std::cout << "Memory difference between a sorted vector and a set: " << vec_size - set_size << " bytes\n";
}
