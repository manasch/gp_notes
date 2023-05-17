#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    int limit = std::sqrt(n);
    for (int i = 2; i <= limit; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> nums(1000000);
    for (int i = 0; i < 1000000; ++i) {
        nums[i] = i + 1;
    }

    // Timing using count_if
    auto start_count = std::chrono::high_resolution_clock::now();
    int count = std::count_if(nums.begin(), nums.end(), is_prime);
    auto end_count = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> count_time = end_count - start_count;
    std::cout << "Found " << count << " primes using count_if in "
              << count_time.count() << " seconds." << std::endl;

    // Timing using find_if
    auto start_find = std::chrono::high_resolution_clock::now();
    auto it = std::find_if(nums.begin(), nums.end(), is_prime);
    int found = 0;
    while (it != nums.end()) {
        ++found;
        it = std::find_if(++it, nums.end(), is_prime);
    }
    auto end_find = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> find_time = end_find - start_find;
    std::cout << "Found " << found << " primes using find_if in "
              << find_time.count() << " seconds." << std::endl;

    return 0;
}
