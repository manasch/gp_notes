#include<iostream>
template<typename T>
void foo(const T& t) {
    std::cout << t.value << std::endl;
}

struct Bar {
  int value = 2;  
};

struct Baz {
    int notvalue = 2;
};
  void foo(const Baz& baz) {
    std::cout << baz.notvalue << std::endl;
  }


int main() {
    foo(Bar());
    foo(Baz());
    return 0;
}