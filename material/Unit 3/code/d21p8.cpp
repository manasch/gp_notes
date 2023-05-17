#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector {1, 2, 3, 4, 5};
    std::vector<int>::iterator it;

    std::cout << "Original Vector: ";
    for (it = myVector.begin(); it != myVector.end(); it++) {
        std::cout << *it << " ";
    }

    int* p = &myVector[0]; // Get a pointer to the first element of the vector

    myVector.resize(10); // Resize the vector to have 10 elements

    std::cout << "\nResized Vector: ";
    for (it = myVector.begin(); it != myVector.end(); it++) {
        std::cout << *it << " ";
    }

    if (p == &myVector[0]) {
        std::cout << "\nsame location";
    }
    else {
        std::cout << "\ndifferent location" << p << '\t' << &myVector[0]; 
    }

    int* q = &myVector[0]; // Get a pointer to the first element of the resized vector

    if (p == q) {
        std::cout << "Same Location";
    }
    else {
        std::cout << "\ndifferent location" << p << '\t' << q; 
    }

    return 0;
}
