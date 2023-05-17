//! moral of the story - use vectors
//! instead of dynamic arrays
//#define TAPPU
#ifdef TAPPU
#include <iostream>

int main() {
    // Dynamically allocate an array of integers
    int* arr = new int[10];

    // Initialize the array with some values
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    // Delete the array twice (mistake!)
    delete[] arr;
    delete[] arr;

    // Access the array (undefined behavior!)
    std::cout << arr[0] << std::endl;

    return 0;
}


#endif
#define SARE
#ifdef SARE
#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> vec(10);

    // Initialize the vector with some values
    for (int i = 0; i < 10; i++) {
        vec[i] = i;
    }

    // Access the vector
    std::cout << vec[0] << std::endl;

    return 0;
}


#endif 