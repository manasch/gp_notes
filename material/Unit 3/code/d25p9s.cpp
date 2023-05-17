#include <iostream>
#include <set>
#include <string>

struct PointerStringLess {
    bool operator()(const std::string* a, const std::string* b) const {
        return *a < *b;
    }
};

int main() {
    std::set<std::string*, PointerStringLess> ssp;
    ssp.insert(new std::string("Anteater"));
    ssp.insert(new std::string("Wombat"));
    ssp.insert(new std::string("Lemur"));
    ssp.insert(new std::string("Penguin"));
    for (std::set<std::string*>::const_iterator i = ssp.begin(); i != ssp.end(); ++i) {
        std::cout << **i << std::endl;
    }
    // deallocate memory
    for (std::string* s : ssp) {
        delete s;
    }
    return 0;
}
