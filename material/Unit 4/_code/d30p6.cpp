// set_terminate example
#include <iostream>       // std::cerr
#include <exception>      // std::set_terminate
#include <cstdlib>        // std::abort

void myterminate () {
  std::cerr << "terminate handler called\n";
  abort();  // forces abnormal termination
}

int main (void) {
  std::set_terminate (myterminate);
  throw 0;  // unhandled exception: calls terminate handler
  return 0;
}