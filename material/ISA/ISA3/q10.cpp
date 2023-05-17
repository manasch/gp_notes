#include <iostream>
#include <list>

int main() {
    std::list<int> mylist;
    mylist.push_back(4);
    mylist.push_front(3);
    mylist.push_front(2);
    mylist.pop_back();
    mylist.pop_front();

    for (auto it = mylist.begin(); it != mylist.end();
         ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    return 0;
}
