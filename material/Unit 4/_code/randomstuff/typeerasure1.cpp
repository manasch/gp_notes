#include <iostream>
#include <memory>
#include <sstream>

// Define a base class that represents the type-erased interface.
class ITypeErased {
public:
    // Declare a virtual destructor to ensure proper cleanup when deleting derived objects.
    virtual ~ITypeErased() = default;

    // Declare pure virtual functions for input and output operations.
    virtual void read(std::istream& input) = 0;
    virtual void write(std::ostream& output) const = 0;
};

// Define a derived class template that will store and manage objects of various types.
template <typename T>
class TypeErased : public ITypeErased {
public:
    // Constructor that takes an object and stores it in the data member.
    TypeErased(T t) : data(std::move(t)) {}

    // Override the read function to read data into the stored object.
    void read(std::istream& input) override {
        input >> data;
    }

    // Override the write function to output the stored object.
    void write(std::ostream& output) const override {
        output << data;
    }

private:
    // A data member that holds the actual object.
    T data;
};

int main() {
    // Create type-erased wrappers around an int and a double.
    std::unique_ptr<ITypeErased> erased_int = std::make_unique<TypeErased<int>>(0);
    std::unique_ptr<ITypeErased> erased_double = std::make_unique<TypeErased<double>>(0.0);

    // Use an input stringstream to simulate reading data from an istream.
    std::istringstream input("42 3.14");
    erased_int->read(input);
    erased_double->read(input);

    // Output the type-erased data using the write function.
    erased_int->write(std::cout); // Output: "42"
    std::cout << std::endl;
    erased_double->write(std::cout); // Output: "3.14"
    std::cout << std::endl;

    return 0;
}
