#include <iostream>
#include <unordered_set>
#include <chrono>

int main() {
    std::unordered_set<int> s;
    //! Some very large insertion loop - 10,00,000 
    bool exists_count = s.count(21);
    bool exists_find = (s.find(21) != s.end());
}
