#include<iostream>
using namespace std;
template <typename T>
T max(T lhs,T rhs) {
    cout << "T\n";
    return (lhs > rhs)? lhs : rhs;
}
double max(double lhs, double rhs) {
    cout << "Fun\n";
    return (lhs > rhs)? lhs : rhs;
}
int main() {
    ::max(10.5f, 5.5f); //  (1)
    ::max(10.5, 5.5);   // (2)
}