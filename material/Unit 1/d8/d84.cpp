// number.cpp

#include <cmath>
#include <string>

template <typename T>
struct Number {
	int absValue() {
        return 5;
    }
  T val{};
};

int main() {
  
    Number<std::string> numb;
    // numb.absValue();       // (1)
  
}
