#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //* Create a vector of integers
    std::vector<int> vec = { 3, 7, 11, 15, 19, 23, 27 };

    //* Count the number of elements greater than 10
    int count = std::count_if(vec.begin(), vec.end(),
     [](int i){ return i > 10; });

    //* Output the count
    std::cout << "Number of elements greater than 10: " << count << std::endl;

    return 0;
}
