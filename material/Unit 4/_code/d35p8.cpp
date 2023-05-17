#include <iostream>
#include <vector>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Circle circle;
    Square square;

    std::vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&square);

    for (const auto& shape : shapes) {
        shape->draw();
    }

    return 0;
}
