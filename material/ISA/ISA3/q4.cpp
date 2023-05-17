#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> my_vec = {1, 2};
  cout << "Value"<< *my_vec.end();
  return 0;
}
//! Prints a \0 , 2, \n, not defined