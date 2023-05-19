// unordered containers
#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <unordered_map>
class MyHash
{
  public:
    int operator()(const string &s) const { return (int)s[0]; }
};
class MyEqual
{
  public:
    bool operator()(const string &lhs, const string &rhs) const
    {
        return lhs[0] == rhs[0];
    }
};
int main()
{
#if 0
	unordered_map<string, string> m;
	m["karnataka"] = "bangalore";
	m["kerala"] = "trivandrum";
	m["tamilnadu"] = "chennai";
	for_each(begin(m), end(m), 
		[](auto p){ cout << p.first << ": " << p.second << "\n";});
	cout << "\n";
#endif
#if 0
	unordered_map<string, string, MyHash> m;
	m["karnataka"] = "bangalore";
	m["kerala"] = "trivandrum";
	m["tamilnadu"] = "chennai";
	for_each(begin(m), end(m), 
		[](auto p){ cout << p.first << ": " << p.second << "\n";});
	cout << "\n";
#endif
    unordered_map<string, string, MyHash, MyEqual> m;
    m["karnataka"] = "bangalore";
    m["kerala"] = "trivandrum";
    m["tamilnadu"] = "chennai";
    for_each(begin(m), end(m),
             [](auto p) { cout << p.first << ": " << p.second << "\n"; });
    cout << "\n";
}
// SFINAE ?
