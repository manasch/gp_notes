#include <iostream>
#include <vector>
#include <memory>

class Container {
public:
    virtual void add(void* item) = 0;
    virtual void* get(int index) = 0;
    virtual int size() = 0;
    virtual ~Container() {}
};

template<typename T>
class VectorContainer : public Container {
public:
    VectorContainer() : data() {}
    void add(void* item) override {
        data.push_back(*reinterpret_cast<T*>(item));
    }
    void* get(int index) override {
        return &data[index];
    }
    int size() override {
        return static_cast<int>(data.size());
    }
private:
    std::vector<T> data;
};

int main() {
    Container* container = new VectorContainer<int>();
    int x = 42;
    container->add(&x);
    int* p = static_cast<int*>(container->get(0));
    std::cout << *p << std::endl;
    delete container;
    return 0;
}
