#include <iostream>
template <typename E>
class Engine {
public:
    void start() {
        std::cout << "Engine of type " << typeid(E).name() << " started." << std::endl;
    }
};

template <typename C, typename E>
class Car {
private:
    Engine<E> engine;
public:
    void start() {
        engine.start();
        std::cout << "Car of type " << typeid(C).name() << " started." << std::endl;
    }
};

int main() {
    Car<int, float> car;
    car.start();
    return 0;
}
