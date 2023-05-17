#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v {5, 6, 29, 1, 4, 1, 2, 3, 9, 
                       10, 3, 2, 1};
    std::vector<int> subseq {1, 2, 3};
    //TODO find the inverted pattern 3,2,1 without 
    //TODO changing subseq or writing additional logic
    
    auto it = std::search(v.begin(), v.end(), subseq.rbegin(), subseq.rend());
    
    if (it != v.end()) {
        std::cout << "Found subsequence starting at position " << std::distance(v.begin(), it) + subseq.size() - 1 << std::endl;
    } else {
        std::cout << "Subsequence not found" << std::endl;
    }
    
    return 0;
}
