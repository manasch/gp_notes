#include <iostream>
#include <vector>
int main() {
  
  std::vector<int> v = {1, 2, 3, 4, 21};
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << "V  "<< std::endl; }

 
  v.assign(3, 10);  
  //* v now contains {10, 10, 10}
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << "V after 1st assign "<< std::endl; }

  std::vector<int> other = {6, 7, 8, 9};
  v.assign(other.begin() + 1, other.end());  
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << "V after other assign " << std::endl; }
  std::cout << "Front: " << v.front() << std::endl;  
  std::cout << "Back: " << v.back() << std::endl;    

  
  v.push_back(10); 
  //* v now contains {7, 8, 9, 10}
  v.pop_back();    
  //* v now contains {7, 8, 9}

  v.resize(5, 0);  
  //* v now contains {7, 8, 9, 0, 0}
  v.resize(2);     
  //* v now contains {7, 8}

  
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " ";  
  //* cout "8 7"
  }
  std::cout << std::endl;
  v.clear();  
  //* v now contains no elements

  return 0;
}
