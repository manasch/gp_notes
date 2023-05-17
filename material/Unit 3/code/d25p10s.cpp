#include <iostream>
#include <vector>
#include <chrono>

int main() {
    //* create two large vectors
    const int size = 100000000;
    std::vector<int> v1(size);
    std::vector<int> v2(size);
    for (int i = 0; i < size; ++i) {
        v1[i] = i;
        v2[i] = i + size;
    }

    //* copy the second half of v2 to v1 using assign()
    auto start_time = std::chrono::high_resolution_clock::now();
    v1.assign(v2.begin() + size/2, v2.end());
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by assign(): " << time_diff.count() << " ms" << std::endl;

    //* copy the second half of v2 to v1 using a for loop
    start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size/2; ++i) {
        v1[i] = v2[i + size/2];
    }
    end_time = std::chrono::high_resolution_clock::now();
    time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken by for loop: " << time_diff.count() << " ms" << std::endl;

    return 0;
}
//* std::vector::assign() is faster than using a for loop to copy the elements because it can take advantage of the memory layout of the vector
//* When a vector is created, it allocates a contiguous block of memory to hold its elements.
//* This means that the elements are stored in adjacent memory locations, which makes it possible to efficiently copy them in bulk.

//* When std::vector::assign() is used to copy a range of elements into a vector, 
//* it can use the memcpy() function to copy the elements in bulk. memcpy() is a low-level function that can copy blocks of memory 
//* very quickly, and is often used in C and C++ code to optimize memory operations
//*  By using memcpy() to copy the elements, std::vector::assign()
//*  can achieve better performance than copying the elements one by one in a loop.
