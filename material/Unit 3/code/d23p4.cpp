
//! when you use emplace(), you pass the 
//! constructor arguments directly 
//! to the function, and 
//! the container constructs the new
//! element in place using those arguments. 
//! This can be more efficient than using 
//! insert() with a temporary object
//! because it avoids the overhead of 
//! creating and copying the temporary object.

//! So, in terms of efficiency, emplace()
//! is usually more efficient than insert()
//! for large objects or when many insertions 
//! are performed. 
//! However,for small objects, the 
//! difference in efficiency 
//! may be negligible.

//! It's worth noting that emplace() 
//! is not available in all containers, 
//! and is only available in containers 
//! that support in-place construction,
//! such as std::set, std::map, 
//! std::unordered_set, 
//! and std::unordered_map.

#include <iostream>
#include <set>

int main() {
    std::multiset<int> mySet;

    // Insert elements using emplace()
    mySet.emplace(2);
    mySet.emplace(1);
    mySet.emplace(4);
    mySet.emplace(3);
    mySet.emplace(4); // Will not be inserted, since it is a duplicate

    // Find an element using find()
    auto it = mySet.find(3);
    if (it != mySet.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    // Check if an element is in the set using count()
    if (mySet.count(4) > 0) {
        std::cout << "Element 4 is in the set" << std::endl;
    } else {
        std::cout << "Element 4 is not in the set" << std::endl;
    }

    // Get range of elements equal to a key using equal_range()
    auto range = mySet.equal_range(4);
    std::cout << "Elements with key 4:";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Get upper bound of a key using upper_bound()
    auto upper = mySet.upper_bound(2);
    if (upper != mySet.end()) {
        std::cout << "Upper bound of key 2: " << *upper << std::endl;
    } else {
        std::cout << "Key 2 is the largest element in the set" << std::endl;
    }

    return 0;
}




