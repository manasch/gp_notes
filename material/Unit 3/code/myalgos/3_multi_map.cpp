/*
multimap :
        key value pairs
        keys need not be unique
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
    multimap<string, string> m;
    // no indexing
    m.insert(pair<string, string>("bangalore", "VITM"));
    m.insert(pair<string, string>("mysore", "jaganmohan palace"));
    m.insert(pair<string, string>("hassan", "shravanabelagola"));

    m.insert(pair<string, string>("bangalore", "planetorium"));
    m.insert(pair<string, string>("hassan", "belur"));
    m.insert(pair<string, string>("mysore", "karanji kere"));
    m.insert(pair<string, string>("hassan", "halebeedu"));
    m.insert(pair<string, string>("bangalore", "ISKCON"));
    m.insert(pair<string, string>("mysore", "brindavan gardens"));
    m.insert(pair<string, string>("bangalore", "cubbon park"));

    disp(begin(m), end(m));

    pair<multimap<string, string>::iterator, multimap<string, string>::iterator>
        p = m.equal_range("hassan");
    cout << "\n";
    disp(p.first, p.second);
}
