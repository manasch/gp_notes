#include <iostream>  
#include <algorithm> 
#include <vector> 
 
using namespace std;
 
int main () 
{
  vector<int> v = {4,2,10,5,1,8};
  if (binary_search(v.begin(), v.end(), 4))
    cout << "found.\n"; 
  else 
  	cout << "not found.\n";
  return 0;
}