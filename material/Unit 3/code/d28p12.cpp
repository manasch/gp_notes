#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v1{ 1, 2, 3, 4, 5 };
    std::vector<int> v2;
    std::vector<int> v3;

    auto is_odd = [](int x) { return x % 2 == 1; };

    std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2), is_odd);

    std::reverse_copy(v2.begin(), v2.end(), std::back_inserter(v3));

    std::cout << "v1: ";
    for (auto i : v1) {
        std::cout << i << " ";
    }
    std::cout << "\nv2: ";
    for (auto i : v2) {
        std::cout << i << " ";
    }
    std::cout << "\nv3: ";
    for (auto i : v3) {
        std::cout << i << " ";
    }

    return 0;
}
