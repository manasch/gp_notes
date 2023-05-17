#include <iostream>
#include <unordered_set>
int main() {
    std::unordered_set<int> myset =
                         {2,4, 6};
    myset.insert(12);
    myset.erase(6);
    std::cout << "The set contains: ";
    for (int x : myset) {
        std::cout << x << ' ';
    }
}
