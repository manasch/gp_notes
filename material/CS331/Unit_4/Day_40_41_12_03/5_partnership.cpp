#include <iostream>
using namespace std;
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
	vector<int> v{ 20, 50, 100, 225, 225, 300 };
	vector<int> d(v.size());
	adjacent_difference(begin(v), end(v), begin(d));
	for_each(begin(d), end(d), [](int e){cout << e << "\t";}); cout << "\n";

}
