#include <iostream>

using namespace std;
template <typename T>
void print(T value, int num) {
    for (int i = 0; i < num; i++) {
        cout << value << endl;
    }
}
int main() {
    int num = 5;
    string value = "Hello, World!";
    double dval = 15.5;
    print(value, num);
    print(dval, num);
    return 0;
}
