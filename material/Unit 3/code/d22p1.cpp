#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    //* Copy elements from v into a new vector 
    //*using iterators
    std::vector<int> subvec;
    std::copy(v.begin() + 2, v.end(),
              std::back_inserter(subvec));
    
    //* Print the elements of the new vector
    for (int elem : subvec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
