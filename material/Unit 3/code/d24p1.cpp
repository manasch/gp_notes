//* Using this stub code change the 
//* age of persons in the objects 
//* put in the vector and see 
//* if they have changed the objects
//* themselves
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
    

    // Add them to a vector
    

    // Print the original info
   

    // Modify the objects in the vector
    //*for (auto& p : yourvector) {
    //*    p.age += 1;
    //*}

    // Print the modified info


    return 0;
}
