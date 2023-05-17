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
    // std::unique_ptr is a 
    // smart pointer that owns and manages another object through a pointer and disposes of that object w
    // hen the unique_ptr goes out of scope. 
    
    // The key feature of unique_ptr is that it ensures the object it points to has only one owner and is automatically
    // deleted when the unique_ptr goes out of scope. This helps prevent memory leaks and simplifies resource management.
    
    // std::make_unique is a typesafe way of creating a unique pointer
    
    std::unique_ptr<ITypeErased> erased_int = std::make_unique<TypeErased<int>>(0);
    
    // Lets break this down from right to left 
    //std::make_unique<TypeErased<int>>(0) creates a unique_ptr to an object of type TypeErased<int>.

    // The TypeErased<int> object is initialized with the value 0.
    // The object is createdT on the heap,
    // std::make_unique returns a unique_ptr that owns and manages the newly created object.
    
    
    // std::unique_ptr<ITypeErased> erased_int creates a unique_ptr named erased_int, 
    //which will store the returned unique_ptr from the std::make_unique call.
    
    //Since TypeErased<int> inherits from ITypeErased, the unique_ptr 
    //can store a pointer to the base class ITypeErased.

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
