#include <iostream>

template <typename T>
class MyClass {
 private:
  T* instance;
  bool created;

 public:
  MyClass() : created(false) {}
  ~MyClass() { if (created) delete instance; }

  T& getInstance() {
    if (!created) {
      instance = new T();
      created = true;
    }
    return *instance;
  }
};

int main() {
  MyClass<int> myClass1;
  int& x1 = myClass1.getInstance();
  x1 = 21;
  MyClass<int> myClass2;
  int& x2 = myClass2.getInstance();
  std::cout << "x1 and x2 are the same: " << (&x1 == &x2) << std::endl;
  return 0;
}
