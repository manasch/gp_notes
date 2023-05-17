#include <iostream>

class Engine {
public:
    void start() {
        std::cout << "Engine started." << std::endl;
    }
    ~Engine()
    {
        std::cout << "Engine destroyed";
    }
};

class Car {
private:
    Engine engine;
public:
    void start() {
        engine.start();
        std::cout << "Car started." << std::endl;
    }
};

int main() {
    Car car;
    car.start();
    return 0;
}
