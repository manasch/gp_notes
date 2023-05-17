//! Pass pointers to make it work
#include <iostream>
#include <vector>

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    void printInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Create some Person objects
    Person p1("Alice", 25);
    Person p2("Bob", 30);
    Person p3("Charlie", 35);

    //! Add pointers to the objects to a vector
    std::vector<Person*> people = {&p1, &p2, &p3};

    // Print the original info
    std::cout << "Original info:" << std::endl;
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();

    // Modify the objects in the vector
    for (auto p : people) {
        //! Deferenced here
        p->age += 1;
    }

    // Print the modified info
    std::cout << "Modified info:" << std::endl;
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();

    return 0;
}
