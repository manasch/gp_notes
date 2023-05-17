// C++ program to demonstrate the use of std::equal_range
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v = { 10, 10, 30, 30, 30, 100, 10,
					300, 300, 70, 70, 80 };

	// Declaring an iterator to store the
	// return value of std::equal_range
	std::pair<std::vector<int>::iterator,
			std::vector<int>::iterator> ip;

	// Sorting the vector v
	sort(v.begin(), v.end());
	// v becomes 10 10 10 30 30 30 70 70 80 100 300 300

	// Using std::equal_range and comparing the elements
	// with 30
	ip = std::equal_range(v.begin(), v.begin() + 12, 30);

	// Displaying the subrange bounds
	cout << "30 is present in the sorted vector from index "
		<< (ip.first - v.begin()) << " till "
		<< (ip.second - v.begin());

	return 0;
}
