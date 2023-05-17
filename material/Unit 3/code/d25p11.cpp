#include <iostream>
#include <map>
#include <chrono>

int main() {
    // create a map of integers to integers
    std::map<int, int> my_map;

    // time inserting 1000000 elements using insert()
    auto start = std::chrono::high_resolution_clock::now();
    //TODO insert elements using insert
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Insert time: " << elapsed_seconds.count() << " seconds\n";

    // clear the map
    my_map.clear();

    // time inserting 1000000 elements using operator[]
     start = std::chrono::high_resolution_clock::now();
    // TODO insert elements using []
    
     end = std::chrono::high_resolution_clock::now();
     elapsed_seconds = end - start;
    std::cout << "[] time: " << elapsed_seconds.count() << " seconds\n";

    return 0;
}
