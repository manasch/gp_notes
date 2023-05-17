/*
map :
        key value pairs
        keys are unique elements
        ordered based on a predicate
        no control over the positioning - cannot insert at pos x
*/
#include <iostream>
using namespace std;
#include <algorithm>
#include <map>
#include <string>
template <typename ptr_t> void disp(ptr_t first, ptr_t last)
{
    while (first != last)
    {
        cout << first->first << "\t" << first->second << "\n";
        ++first;
    }
    cout << "\n";
}
int main()
{
    map<string, int> m;
    m["ramanujan"] = 1729;
    m["armstrong"] = 153;
    m["prime"] = 29;
    disp(begin(m), end(m));

    cout << "prime : " << m["prime"] << "\n";
    cout << "perfect : " << m["perfect"] << "\n"; // 0
    // value_type()
    // key and value get stored
    disp(begin(m), end(m));
}
