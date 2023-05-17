#include <iostream>
#include <vector>
#include <memory>
#include <any>

class Container {
public:
    virtual void add(std::any item) = 0;
    virtual std::any get(int index) = 0;
    virtual int size() = 0;
    virtual ~Container() {}
};

class VectorContainer : public Container {
public:
    VectorContainer() : data() {}
    void add(std::any item) override {
        data.push_back(item);
    }
    std::any get(int index) override {
        return data[index];
    }
    int size() override {
        return static_cast<int>(data.size());
    }
private:
    std::vector<std::any> data;
};

int main() {
    Container* container = new VectorContainer();
    int x = 42;
    double y = 3.14;
    std::string z = "hello";
    container->add(x);
    container->add(y);
    container->add(z);
    int p = std::any_cast<int>(container->get(0));
    double q = std::any_cast<double>(container->get(1));
    std::string r = std::any_cast<std::string>(container->get(2));
    std::cout << p << " " << q << " " << r << std::endl;
    delete container;
    return 0;
}
