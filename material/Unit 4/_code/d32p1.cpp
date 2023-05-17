#include <iostream>
#include <utility>

using namespace std;

//Since C++17 one can use fold expression to calculate factorial:
template <class T, T N, class I = std::make_integer_sequence<T, N>>
struct factorial;

template <class T, T N, T... Is>
struct factorial<T, N, std::integer_sequence<T, Is...>> {
   static constexpr T value = (static_cast<T>(1) * ... * (Is + 1));
};

int main(int argc, char** argv) {
    std::cout << factorial<int, 5>::value << std::endl;
    return 0;
}
