#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> vec;
    vector<string>::iterator iter;

    vec.push_back("India ");
    vec.push_back("Bharat ");
    vec.push_back("Hindustan ");
    iter = vec.begin();
    while (iter != vec.end()) {
        ++iter;
        cout << *iter;
    }

    return 0;
}
