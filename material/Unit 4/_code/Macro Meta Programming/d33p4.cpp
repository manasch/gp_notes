#include <iostream>
#define trace(code) code; std::cout<<#code<<"\n";

int main() {
    int i = 5;
    int x = 0;
    trace( x=3; )
    trace( x+=2; )
    trace( i*=x; )
    std::cout << "x = " << x << std::endl;
    std::cout << "i = " << i << std::endl;
    return 0;
}
