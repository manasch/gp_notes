#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;

    d.push_back(10);
    d.push_front(20);
    d.push_back(30);

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }

    return 0;
}
