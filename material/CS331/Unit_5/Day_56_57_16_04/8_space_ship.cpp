#include <iostream>
using namespace std;
struct Pair
{
    Pair(int x, int y) : x(x), y(y) {}
    auto operator<=>(const Pair &) const = default;
    int x;
    int y;
};
int main()
{
    cout << ((10 <=> 10) == strong_ordering::equal) << "\n";
    cout << ((10 <=> 20) == strong_ordering::less) << "\n";
    // cout << int(10 <=> 5) << "\n";
    Pair a(10, 20);
    Pair b(10, 20);
    cout << ((a <=> b) == strong_ordering::equal) << "\n";
    cout << ((a <=> b) == strong_ordering::less) << "\n";
    cout << (a < b) << "\n";
}
