#include <iostream>
#include <map>
#include <chrono>

int main() {
    //* create a map of integers to integers
    std::map<int, int> my_map;

    //* time inserting 1000000 elements using insert()
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        my_map.insert({i, i});
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Insert time: " << elapsed_seconds.count() << " seconds\n";

    //* clear the map
    my_map.clear();

    //* time inserting 1000000 elements using operator[]
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        my_map[i] = i;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "[] time: " << elapsed_seconds.count() << " seconds\n";

    return 0;
}
//* As you can see, std::map::insert() is faster than std::map::operator[](). 
//* The reason for this is that operator[] first searches for the key in the map and returns a reference to its value if it exists
//* . If the key does not exist, operator[] creates a new element with the given key and default-constructed value, which can be expensive. 
//* On the other hand, insert takes a std::pair representing a key-value pair and inserts it into the map, without performing any search. 
//* This can be faster than operator[] when you know the key-value pairs ahead of time.