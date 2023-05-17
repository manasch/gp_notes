#include <iostream>
#include <vector>

template <typename Derived>
class Shape {
public:
    void draw() {
        static_cast<Derived*>(this)->draw_impl();
    }
};

class Circle : public Shape<Circle> {
public:
    void draw_impl() {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape<Square> {
public:
    void draw_impl() {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Circle circle;
    Square square;

    std::vector<Shape<Circle>*> circle_shapes;
    circle_shapes.push_back(&circle);

    std::vector<Shape<Square>*> square_shapes;
    square_shapes.push_back(&square);

    for (const auto& shape : circle_shapes) {
        shape->draw();
    }

    for (const auto& shape : square_shapes) {
        shape->draw();
    }

    return 0;
}
