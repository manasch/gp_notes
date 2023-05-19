#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// algorithms:
// <algorithm>
// 1. non-mutating algorithms 
//		for_each(ptr_t first, ptr_t last, fn_t fn)
// 2. mutating algorithms
// 3. sort related algorithms
// <numeric>
// 4. numeric algorithms

int main()
{
	int a[] = {11, 22, 33, 44, 55};
	vector<int> v{10, 20, 30, 40, 50};
	for_each(begin(a), end(a), [](int e){cout << e << "\t";}); cout << "\n";
	int s = 0;
	auto f = for_each(begin(a), end(a), [&s](int e){s += e;}); cout << s << "\n";
	s = 0;
	for_each(begin(v), end(v), f); cout << s << "\n";
	
	for_each(rbegin(a), rend(a), [](int e){cout << e << "\t";}); cout << "\n";

}




