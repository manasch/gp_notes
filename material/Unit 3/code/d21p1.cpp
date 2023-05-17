#define BASIC
#ifdef BASIC
#include <iostream>
#include <utility> //TODO  for std::pair
// TODO The first our containers
// TODO Holds 2 members of different type

int main() {
    std::pair<std::string, int> person; // create a pair of string and integer types
    person.first = "X"; 
    person.second = 25; 
    
    std::cout << "Name: " << person.first << ", Age: " << person.second << std::endl;
    return 0;
}
#endif 

//#define MAKEPAIR
#ifdef MAKEPAIR
#include <iostream>
#include <utility> // for std::pair, std::make_pair

int main() {
    std::pair<std::string, int> person = std::make_pair("Y", 24);
    
    std::cout << "Name: " << person.first << ", Age: " << person.second << std::endl;
    return 0;
}

#endif
