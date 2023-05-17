#include <iostream>
#include <vector>
int main() {
    //* Create a vector of integers with initial capacity of 10
    std::vector<int> vec(10);

    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    //TODO Trim the excess capacity
    

    std::cout << "Capacity after trimming excess capacity: " << vec.capacity() << std::endl;

    return 0;
}
