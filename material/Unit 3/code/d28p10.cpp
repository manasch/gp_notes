#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    
    std::vector<int> coll2 {5, 3, 2, 1, 4, 7, 9, 8, 6}; // out of heap order
    std::vector<int> coll3 {4,3,2,1};

    
    bool coll2_is_heap = std::is_heap(coll2.begin(), coll2.end());
    bool coll3_is_heap = std::is_heap(coll3.begin(), coll3.end());
    
    std::cout << "coll2 is heap: " << std::boolalpha << coll2_is_heap << std::endl; // prints "coll2 is heap: false"
    std::cout << "coll3 is heap: " << std::boolalpha << coll3_is_heap << std::endl; 
    return 0;
}
