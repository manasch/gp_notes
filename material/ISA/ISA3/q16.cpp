#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 10, 20, 30, 40, 50, 60, 70,80};
    std::vector<int> subseq = { 40, 50 };
    auto itr = std::search(vec.rbegin(),
     vec.rend(), 
     subseq.rbegin(), subseq.rend());
    if (itr != vec.rend()) {
        std::cout << "Subsequence found at index " 
        << std::distance(itr, vec.rend()) - subseq.size() 
        << std::endl;
    } else { 
        std::cout << "Subsequence not found" 
        << std::endl;
    }

    return 0;
}
