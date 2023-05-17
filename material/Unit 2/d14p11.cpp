#include <iostream>
#include <vector>
// No memory leaks here in composition
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
        for (auto& person : people) {
            delete person;
        }
        for (auto& house : houses) {
            delete house;
        }
    }
    void add_person(Person* person) {
        people.push_back(person);
    }
    void add_house(House* house) {
        houses.push_back(house);
    }
private:
    std::vector<Person*> people;
    std::vector<House*> houses;
};

int main() {
    std::cout << "Entering main." << std::endl;
    Town* town = new Town();
    town->add_person(new Person("John"));
    town->add_house(new House("123 Main St."));
    delete town;
    std::cout << "Leaving main." << std::endl;
    return 0;
}
