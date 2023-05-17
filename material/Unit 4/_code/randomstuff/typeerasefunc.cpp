#include <iostream>
#include <memory>
#include <functional>

class ITypeErased {
public:
    virtual ~ITypeErased() = default;
    virtual void execute() = 0;
};

template <typename T>
class TypeErased : public ITypeErased {
public:
    // Modify the constructor to accept a const reference
    TypeErased(const T& t) : data(t) {}

    void execute() override {
        data();
    }

private:
    T data;
};

void print_hello() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    std::unique_ptr<ITypeErased> type_erased = std::make_unique<TypeErased<std::function<void()>>>(print_hello);
    type_erased->execute(); // Output: "Hello, World!"

    return 0;
}
