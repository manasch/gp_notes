#include <iostream>
#include <vector>
//! Can you insert in the beginning of a vector
//! Yes at a huge cost
int main() {
    std::vector<int> myVector {1, 2, 3, 4, 5};
    std::vector<int>::iterator it;

    std::cout << "Original Vector: ";
    for (it = myVector.begin(); it != myVector.end(); it++) {
        std::cout << *it << " ";
    }

    myVector.insert(myVector.begin(), 0); //! Insert 0 at the beginning of the vector

    std::cout << "\nNew Vector: ";
    for (it = myVector.begin(); it != myVector.end(); it++) {
        std::cout << *it << " ";
    }

    return 0;
}
