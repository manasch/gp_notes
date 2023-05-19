#include <iostream>
using namespace std;

#include <vector>

int main()
{
    vector<int> v{11, 22, 33, 44};
    vector<int>::iterator it = begin(v) + 2;
    cout << "val : " << *it << "\n"; // 33
    v.push_back(55);
    cout << "val : " << *it << "\n"; // undefined
}
// vector can get resized on a push_back
// size is increased; normally doubled
// memory should be contiguous
// old content is copied to the new location
// old location conceptually is given back
// what happens to pointers, references and iterators which point to old
// locations?
//		conceptually become invalid on a push_back
