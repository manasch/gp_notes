#include <iostream>
using namespace std;

enum class Month { January, February, March, April, May, June, July,
                   August, September, October, November, December };

int main()
{
    // Instantiating the Enum Class
    Month m = Month::June;

    // Comparison now is completely type-safe
    if (m == Month::May)
        cout << "It's May\n";
    else
        cout << "It's not May\n";

    // can't use an enum value to create variables
    // int March = 3; // gives an error

    // won't work as there is no implicit conversion to int
    // cout << m; // gives an error

    // can convert enum value to int explicitly
    cout << static_cast<int>(m);

    return 0;
}
