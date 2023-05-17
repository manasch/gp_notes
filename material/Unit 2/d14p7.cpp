#include <memory>

class Part {};

// Here the destructor work is delegated to
// a smart pointer which clears up part_ 
template <typename T>
class Composite {
 public:
  Composite() : part_(std::make_shared<T>()) {}
  ~Composite() {}

 private:
  std::shared_ptr<T> part_;
};

int main() {
  Composite<Part> composite;
  return 0;
}
