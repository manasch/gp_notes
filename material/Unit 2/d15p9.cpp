#include<iostream>
#include<functional>
using namespace std;
template<typename T1, typename T2>
void combine(T1 x, T2 y) {
    std::cout << x + y << std::endl;
}

class Mixer {
friend void combine<>(int&, int&);
friend void combine<int, int>(int, int);
friend void combine<char>(char, int);
};
class Fixer {

};

int main() {
    int x = 5;
    int y = 10;
    combine(x, y);
    combine(10, 20);
    combine(std::ref(x), std::ref(y));
    combine('a', 10);
    std::cout << "attempting float";
    combine<float,float>(10.2f,11.2f);
}
// friend void combine<char>(char&, int);
// ERROR: doesn’t match combine() template
//friend void combine<>(long, long) { ... }
// ERROR: definition not allowed!