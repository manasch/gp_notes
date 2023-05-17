#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v {3, 2, 5, 8, 1, 9};
    
    auto [min_it, max_it] = std::minmax_element(v.begin(), v.end());
    
    std::cout << "Smallest element: " << *min_it << std::endl;
    std::cout << "Largest element: " << *max_it << std::endl;
    std::cout << "Distance between smallest and largest elements: " 
              << std::distance(min_it, max_it) << std::endl;
    
    return 0;
}
