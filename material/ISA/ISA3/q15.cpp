#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v {9, 7, 6, 1, 2, 3};
    std::vector<int> pattern {1, 2, 3};

    auto it = std::search(v.begin(), v.end(), pattern.begin(), pattern.end());

    if (it != v.end()) {
        std::cout << "Pattern found at index " << std::distance(v.begin(), it) << std::endl;
    } else {
        std::cout << "Pattern not found" << std::endl;
    }

    return 0;
}
