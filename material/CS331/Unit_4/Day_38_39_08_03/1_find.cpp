#include <iostream>
using namespace std;
#include <algorithm>
#include <functional>
#include <vector>

bool odd(int n) { return n % 2; }
struct Greater_14
{
    bool operator()(int x) { return x > 14; }
};

struct MyGreater1
{
    MyGreater1(int y) : y(y) {}
    bool operator()(int x) { return x > y; }
    int y;
};

template <typename pred_t, typename T> class MyBind
{
  public:
    MyBind(pred_t pred, T t) : y(t), pred(pred) {}
    bool operator()(T x) { return pred(x, y); }

  private:
    pred_t pred;
    T y;
};

int main()
{
    vector<int> v{10, 4, 14, 25, 15, 30};
    vector<int>::iterator it;

    it = find(begin(v), end(v), 15);
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }
    // find the first odd number
    it = find_if(begin(v), end(v), odd);
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }

    // find a number greater than a given #
    // greater than 14?
    it = find_if(begin(v), end(v), Greater_14());
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }

    // it = find_if(begin(v), end(v), greater<int>(), 14); // NO; too many arg
    it = find_if(begin(v), end(v), MyGreater1(14)); // callable has a state
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }
    // how to convert a binary predicate to a unary predicate?
    // if a function requires two arguments, we can fix one and give another
    //	each time, how do we convert this function to accept one argument

    // adaptor : design pattern
    //	mismatch of interface
    //
    // it = find_if(begin(v), end(v), MyBind(greater<int>(), 14) );
    it = find_if(begin(v), end(v),
                 MyBind(greater<int>(), 14)); // callable has a state
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }

    it = find_if(begin(v), end(v), bind(greater<int>(), placeholders::_1, 14));
    // callable has a state
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }

    it = find_if(begin(v), end(v),
                 [](int rhs) { return greater<int>()(rhs, 14); });
    // callable has a state
    if (it == end(v))
    {
        cout << "not found\n";
    }
    else
    {
        cout << "found : " << *it << "\n";
    }
}
