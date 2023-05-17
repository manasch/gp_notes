#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    const int n = 1000000;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i;
    }
    
    // Count prime numbers using const_iterator
    auto start_time = std::chrono::high_resolution_clock::now();
    int num_primes = std::count_if(nums.cbegin(), nums.cend(), is_prime);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Using const_iterator: Found " << num_primes << " prime numbers in "
              << elapsed_time.count() << " seconds." << std::endl;
    
    // Count prime numbers using iterator
    start_time = std::chrono::high_resolution_clock::now();
    num_primes = std::count_if(nums.begin(), nums.end(), is_prime);
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = end_time - start_time;
    std::cout << "Using iterator: Found " << num_primes << " prime numbers in "
              << elapsed_time.count() << " seconds." << std::endl;
    
    return 0;
}
