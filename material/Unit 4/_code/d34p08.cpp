#include <iostream>

 #define DEBUG // Define DEBUG macro

int main() {
#ifdef DEBUG // Use conditional compilation to check if DEBUG macro is defined
   std::cout << "Debugging enabled" << std::endl;
#endif

   // Your driver code here
   const int x = 10;
   const int y = 20;
   constexpr int z = x + y;

   std::cout << "The sum of " << x << " and " << y << " is " << z << std::endl;

   return 0;
}
