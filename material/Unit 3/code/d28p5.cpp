#include <iostream>
#include <vector>
#include <algorithm>

class Person {
public:
    std::string name;
    int age;
    
    Person(std::string n, int a) : name(n), age(a) {}
};

int main() {
    std::vector<Person> people {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 40},
        {"Dave", 20},
        {"Eve", 35}
    };
    
    auto [youngest, oldest] = std::minmax_element(people.begin(), people.end(),
        [](const Person& p1, const Person& p2) {
            return p1.age < p2.age;
        });
    
    std::cout << "The youngest person is " << youngest->name << " (" << youngest->age << ")" << std::endl;
    std::cout << "The oldest person is " << oldest->name << " (" << oldest->age << ")" << std::endl;
    
    return 0;
}
