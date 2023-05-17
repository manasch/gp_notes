#include <iostream>
#include <vector>
void modify_container(
  std::vector<int>::const_iterator it) 
  {
  *it = 10; 
  }
int main() {
  std::vector<int> my_vector = {1, 2};
  modify_container(my_vector.begin());
  std::cout << my_vector[3];
  return 0; }
