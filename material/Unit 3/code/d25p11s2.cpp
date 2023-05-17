#include <iostream>
#include <map>
#include <chrono>

int main() {
    // create an empty map
    std::map<int, int> my_map;

    // time the execution of [] insertion
    auto start = std::chrono::high_resolution_clock::now();
    my_map[9999999999] = 42;
    auto end = std::chrono::high_resolution_clock::now();
    auto time_diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Time taken by []: " << time_diff.count() << " ns" << std::endl;

    // clear the map
    my_map.clear();

    // time the execution of insert
    start = std::chrono::high_resolution_clock::now();
    my_map.insert({9999999999, 42});
    end = std::chrono::high_resolution_clock::now();
    time_diff = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Time taken by insert: " << time_diff.count() << " ns" << std::endl;

    return 0;
}
