#include <iostream>
#include <vector>

int main() {
  //* Create a sequence with n copies of t
  std::vector<int> v1(5, 10);
  std::cout << "v1: ";
  for (auto& x : v1) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  //* Create a sequence with the elements
  //* of the range [i, j)
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  std::vector<int> v3(v2.begin() + 1, v2.end() - 1);
  std::cout << "v3: ";
  for (auto& x : v3) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  //* Insert a copy of t before
  //* the location p
  std::vector<int> v4 = {1, 2, 3};
  auto it = v4.insert(v4.begin() + 1, 10);
  std::cout << "v4: ";
  for (auto& x : v4) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  //* Insert n copies of t
  //* before the location p
  std::vector<int> v5 = {1, 2, 3};
  v5.insert(v5.begin() + 1, 3, 10);
  std::cout << "v5: ";
  for (auto& x : v5) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  //* Insert the elements of the range
  //* [i, j) before the location p
  std::vector<int> v6 = {1, 2, 3};
  std::vector<int> v7 = {4, 5};
  v6.insert(v6.begin() + 1, v7.begin(), v7.end());
  std::cout << "v6: ";
  for (auto& x : v6) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  //* Delete the element pointed to by q
  std::vector<int> v8 = {1, 2, 3};
  auto it2 = v8.erase(v8.begin() + 1);
  std::cout << "v8: ";
  for (auto& x : v8) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  //* Delete the elements of the range [q1, q2)
  std::vector<int> v9 = {1, 2, 3, 4, 5};
  v9.erase(v9.begin() + 1, v9.end() - 1);
  std::cout << "v9: ";
  for (auto& x : v9) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  //* Delete all elements
  std::vector<int> v10 = {1, 2, 3};
  v10.clear();
  std::cout << "v10: ";
  for (auto& x : v10) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
