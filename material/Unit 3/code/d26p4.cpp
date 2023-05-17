#include <iostream>
#include <vector>
#include <algorithm>

class AddOne {
public:
    template <typename T>
    void operator()(T& t) const {
        t += 1;
    }
};

class Person {
public:
    Person(std::string n, int a) : name(n), age(a) {}

    void printInfo() const {
        std::cout << name << " is " << age << " years old." << std::endl;
    }

    void addOneToAge() {
        age += 1;
    }

private:
    std::string name;
    int age;
};

class Rectangle {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void printInfo() const {
        std::cout << "Rectangle has width " << width << " and height " << height << std::endl;
    }

    void addOneToSides() {
        width += 1;
        height += 1;
    }

private:
    double width;
    double height;
};

template <>
void AddOne::operator()(Person& p) const {
    p.addOneToAge();
}

template <>
void AddOne::operator()(Rectangle& r) const {
    r.addOneToSides();
}

int main() {
    std::vector<int> intVec{1, 2, 3, 4, 5};
    std::vector<Person> personVec{{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};
    std::vector<Rectangle> rectVec{{10.0, 20.0}, {15.0, 25.0}};

    std::for_each(intVec.begin(), intVec.end(), AddOne{});
    std::for_each(personVec.begin(), personVec.end(), AddOne{});
    std::for_each(rectVec.begin(), rectVec.end(), AddOne{});

    std::cout << "Updated int vector: ";
    for (const auto& x : intVec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Updated person vector:" << std::endl;
    for (const auto& p : personVec) {
        p.printInfo();
    }

    std::cout << "Updated rectangle vector:" << std::endl;
    for (const auto& r : rectVec) {
        r.printInfo();
    }

    return 0;
}
