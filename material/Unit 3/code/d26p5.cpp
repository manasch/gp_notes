#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
void addOneInt(int& i) {
    i += 1;
}
void addOneComplex(std::complex<double>& c) {
    c.real(c.real() + 1);
    c.imag(c.imag() + 1);
}
int main() {
    std::vector<int> intVec{1, 2, 3, 4, 5};
    std::vector<std::complex<double>> complexVec{{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    std::for_each(intVec.begin(), intVec.end(),
     addOneInt);
    std::for_each(complexVec.begin(), complexVec.end(), 
    addOneComplex);
    std::cout << "Updated int vector: ";
    for (const auto& x : intVec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Updated complex vector: ";
    for (const auto& c : complexVec) {
        std::cout << "(" << c.real() << ", " << c.imag() << ") ";
    }
    std::cout << std::endl;
    return 0;
}
