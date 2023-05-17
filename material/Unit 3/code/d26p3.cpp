template<class InputIterator,
 class Function>
Function for_each(InputIterator first
  , InputIterator last, Function fn)
{
  while (first!=last) {
    fn (*first);
    ++first;
  }
  return fn;      
  //* or, since C++11: return move(fn);
}
#include <iostream>
#include <vector>
void addOne(int& x) {
    x += 1;
    std::cout << x << " ";
}
int main() {
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for_each(nums.begin(), nums.end(), 
    addOne); //* Function Pointer
    return 0;
}
