#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	vector<string> v{"apple", "zebra", "orange", "pineapple", "areca", "zzz"};
	auto it = min_element(begin(v), end(v));
	if(it != end(v))
	{
		cout << *it << "\n";
	}
	it = min_element(begin(v), end(v), [](auto lhs, auto rhs)
			{ return lhs.size() < rhs.size(); });
	if(it != end(v))
	{
		cout << *it << "\n";
	}
	auto s = min<string>("rama", "krishna");
	cout << s << "\n";
	s = min<string>("rama", "krishna", [](auto lhs, auto rhs)
			{ return lhs.size() < rhs.size(); });
	cout << s << "\n";

	s = min<string>({"rama", "krishna", "amar", "beena"});
	cout << s << "\n";
	
	
	
}
