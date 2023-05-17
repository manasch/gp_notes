#include <vector>
#include <cassert>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    //! in this case int
    using value_type = std::vector<int>::value_type;
    static_assert(std::is_same_v<value_type, int>);
    
    //! in this case int &
    value_type& ref = v[0];
    ref = 42;
    assert(v[0] == 42);
    
    //* const_reference
    const value_type& cref = v[1];
    assert(cref == 2);
    
    //! iterator - *ptr
    using iterator = std::vector<int>::iterator;
    iterator it = v.begin();
    *it = 10;
    assert(v[0] == 10);
    
    //! const_iterator - cannot be used for modification
    using const_iterator = std::vector<int>::const_iterator;
    const_iterator cit = v.cbegin();
    assert(*cit == 10);
    
    //! difference_type - distance between 2 iterators
    using difference_type = std::vector<int>::difference_type;
    static_assert(std::is_same_v<difference_type, std::ptrdiff_t>);
    
    //! size_type number of elements 
    using size_type = std::vector<int>::size_type;
    size_type size = v.size();
    assert(size == 5);
}
//#define SUPPLEMENT
#ifdef SUPPLEMENT
//* constant iterator meaning
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};

  // using iterator to modify elements
  for (auto it = v.begin(); it != v.end(); ++it) {
    *it *= 2;
  }

  // using const_iterator to read elements
  for (auto cit = v.cbegin(); cit != v.cend(); ++cit) {
    std::cout << *cit << " ";
  }
  std::cout << std::endl;

  return 0;
}

//* difference - used usually with std::difference
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::vector<int>::iterator it1 = v.begin();
  std::vector<int>::iterator it2 = v.end(); 

  //! difference type maybe unsigned int for forward
  //! iterators

  std::vector<int>::difference_type diff =
                            std::distance(it1, it2);

  std::cout << "Distance between iterators: " 
  << diff << std::endl;

  //* Not a good idea but will work
  std::vector<int>::difference_type dist = it2 - it1;

  return 0;
}

#endif