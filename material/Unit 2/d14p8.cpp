#include <iostream>

class Part {};

class Composite {
 public:
  Composite(const Part& part) : part_(part) {}
  ~Composite() {}

 private:
  Part part_;
};
/* Here instead of composite creating a part 
uses an already created part */
int main() {
  Part part;
  Composite composite(part);
  return 0;
}
