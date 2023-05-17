#include <iostream>
template <typename T>
class RectangleArea {
public:
  static T calculate_area(T width, T height) {
    return width * height;
  }
};
template <typename T, typename cal_Area>
class Shape {
public:
  Shape(T a, T b) : m_a(a), m_b(b) {}
  T area() const {
    return cal_Area::calculate_area(m_a, m_b);
  }
private:
  T m_a;
  T m_b;
};

int main() {
  Shape<double, RectangleArea<double>> rectangle(3.0, 4.0);
  std::cout << "Rectangle area: " << rectangle.area() << std::endl;
  return 0;
}
