 #include <iostream>
    #include <set>
    using namespace std;
    int main()
    {
        set<int> tst;
        tst.insert(7);
        tst.insert(21);
        tst.insert(1008);
        tst.insert(108);
        set<int> :: const_iterator pos;
        for(pos = tst.begin(); pos != tst.end(); ++pos)
        cout << *pos << ' ';
        return 0;
    }