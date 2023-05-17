#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v1{ 1, 2, 3, 4 };
    std::vector<int> v2(4);

    std::copy_backward(v1.begin(), v1.end(), v2.end());

    std::cout << "v1: ";
    for (auto i : v1) {
        std::cout << i << " ";
    }
    std::cout << "\nv2: ";
    for (auto i : v2) {
        std::cout << i << " ";
    }

    return 0;
}
