#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int main()
{
	vector<int> v{20, 10, 20, 30, 20, 20, 40, 20, 20, 20, 50, 20, 20};
	for_each(begin(v), end(v), [](int e){cout << e << "\t";}); cout << "\n";
	vector<int>::iterator it_end = remove(begin(v), end(v), 20);
//	for_each(begin(v), end(v), [](int e){cout << e << "\t";}); cout << "\n";
	for_each(begin(v), it_end, [](int e){cout << e << "\t";}); cout << "\n";
	v.erase(it_end, end(v));
	for_each(begin(v), end(v), [](int e){cout << e << "\t";}); cout << "\n";
}
