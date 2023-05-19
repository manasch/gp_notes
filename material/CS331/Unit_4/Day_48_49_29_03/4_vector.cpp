#include <iostream>
using namespace std;
#include <vector>

template <typename T1, typename T2> class Pair
{
  public:
    T1 first;
    T2 second;
    Pair(T1 f, T2 s) : first(f), second(s) { cout << "ctor\n"; }
    Pair(const Pair &p) : first(p.first), second(p.second)
    {
        cout << "copy ctor\n";
    }
    ~Pair() { cout << "dtor\n"; }
};

int main()
{
#if 0
	{
		vector<Pair<int, int>> v;
		v.push_back(Pair(20, 30));
	}
	/*
	ctor
	copy ctor
	dtor
	dtor
	*/
#endif
#if 0
	{
		vector<Pair<int, int>> v;
		v.emplace_back(20, 30); // avoids creating a temporary object
	}
	/*
	ctor
	dtor
	*/
#endif
    {
        Pair<int, int> p(11, 22);
        vector<Pair<int, int>> v;
        v.emplace_back(p);
    }
}
