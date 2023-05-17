#include <iostream>
#include <vector>
int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.begin()+1;
  std::cout << "Value at iterator position: " << it[0] << std::endl;
  return 0;
}
