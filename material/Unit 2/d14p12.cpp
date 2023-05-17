#include <iostream>
#include <memory>
#include<vector>
using namespace std;

// I can delegate this to shared pointers to
// this for me

class Person {
public:
    Person(const std::string& name) : name(name) {}
    ~Person() {
        std::cout << name << " died." << std::endl;
    }
    std::string name;
};

class House {
public:
    House(const std::string& address) : address(address) {}
    ~House() {
        std::cout << "House at " << address << " was destroyed." << std::endl;
    }
    std::string address;
};

class Town {
public:
    Town() {
        std::cout << "Town was created." << std::endl;
    }
    ~Town() {
        std::cout << "Town was destroyed." << std::endl;
    }
    void add_person(const std::shared_ptr<Person>& person) {
        people.push_back(person);
    }
    void add_house(const std::shared_ptr<House>& house) {
        houses.push_back(house);
    }
private:
    std::vector<std::shared_ptr<Person>> people;
    std::vector<std::shared_ptr<House>> houses;
};

int main() {
    std::cout << "Entering main." << std::endl;
    std::shared_ptr<Town> town = std::make_shared<Town>();
    town->add_person(std::make_shared<Person>("John"));
    town->add_house(std::make_shared<House>("123 Main St."));
    std::cout << "Leaving main." << std::endl;
    return 0;
}
