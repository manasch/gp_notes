#include <iostream>
#include <vector>
#include <algorithm>

bool is_double(const int& a, const int& b) {
    return a == b * 2;
}

int main() {
    std::vector<int> v {1, 2, 3, 4, 5, 6, 4, 8, 12, 16};
    std::vector<int> subseq {2, 4, 6};
    
    auto it = std::search(v.begin(), v.end(), subseq.begin(), subseq.end(), is_double);
    if (it != v.end()) {
        std::cout << "Found at index " << std::distance(v.begin(), it) << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    return 0;
}
