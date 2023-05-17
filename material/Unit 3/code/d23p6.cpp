#include <iostream>
#include <map>
#include <string>

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

int main() {
    std::map<std::string, std::string, cmpByStringLength> myMap;

    // Add some key-value pairs to the map
    myMap["hello"] = "world";
    myMap["apple"] = "pie";
    myMap["car"] = "race";
    myMap["cat"] = "meow";
    myMap["banana"] = "split";

    // Print out the keys and values in the map
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
