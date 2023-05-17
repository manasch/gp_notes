#include <iostream>
#include <set>
int main() {
    std::set<int> myset = {4, 2, 6};
    myset.insert(12);
    myset.erase(6);
    std::cout << "The set contains: ";
    for (int x : myset) {
        std::cout << x << ' ';
    }
}
