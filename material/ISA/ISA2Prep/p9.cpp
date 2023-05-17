#include <iostream>
template <typename T>

constexpr T pi = T(3.14159265358979323846);
constexpr T lifeofpi = T(3.14159265358979323846);


int main() {
  std::cout << pi<int> << std::endl;
  std::cout << pi<double> << std::endl;
  std::cout << lifepi<double> << std::endl;
  return 0;
}
// data section
// 2 or 3 locations 
