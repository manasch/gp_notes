#include <iostream>
#include <vector>
//! resize the vector
int main() {
    std::vector<int> myVector {1, 2, 3, 4, 5};
    std::vector<int>::iterator it;

    std::cout << "Original Vector: ";
    for (it = myVector.begin(); it != myVector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout <<myVector.size() << std::endl;
    myVector.push_back(11);
    //! Keeps growing dynamically
    std::cout <<myVector.size();

    myVector.resize(10); // Resize the vector to have 10 elements

    std::cout << "\nResized Vector: ";
    for (it = myVector.begin(); it != myVector.end(); it++) {
        std::cout << *it << " ";
    }

    return 0;
}
