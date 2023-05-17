#include <atomic>
#include <stdexcept>
#include <iostream>

template <typename Derived, size_t N>
struct limited_instances {
  static std::atomic<size_t> count;
  limited_instances() {
    if (count >= N)
      throw std::logic_error{ "Too many instances" };
    ++count;
  }
  ~limited_instances() { --count; }

  void draw() {
    static_cast<Derived*>(this)->draw_impl();
  }
};

template <typename Derived, size_t N>
std::atomic<size_t> limited_instances<Derived, N>::count = 0;

struct excalibur : limited_instances<excalibur, 1> {
  void draw_impl() {
    std::cout << "Drawing Excalibur\n";
  }
};

struct book_of_magic : limited_instances<book_of_magic, 3> {
  void draw_impl() {
    std::cout << "Drawing Book of Magic\n";
  }
};

int main() {
  excalibur e1;
  //excalibur e2; // error: Too many instances

  book_of_magic b1;
  book_of_magic b2;
  book_of_magic b3;
  //book_of_magic b4; // error: Too many instances

  e1.draw();
  b1.draw();

  return 0;
}
