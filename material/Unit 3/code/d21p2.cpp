// * std ::allocator is designed
// * specifically for allocating memory for containers,
// * such as std::vector, std::list, and std::map. 
// * It is not typically used for
// * allocating memory for other types of objects.
// * Performance: 
// * std::allocator is designed to be more efficient
// * than new when allocating memory for containers. 
// * It can pre-allocate a block of memory and 
// * subdivide it into smaller pieces as needed,
// * reducing the number of 
// * calls to the underlying memory allocation function.
// * I can create my own custom allocator see ALLOCATE
#include <vector>
#include <iostream>
#include <memory>

#define BASE
#ifdef BASE

int main() {
  std::vector<int, std::allocator<int>> v(10); // create a vector of 10 integers
  std::allocator<int> alloc; // create an allocator for int

  //! allocate memory for 5 integers and 
  //!construct them with the default value of 0
  int* p = alloc.allocate(5);
  for (int i = 0; i < 5; i++) {
    alloc.construct(p + i, 0);
  }

  //! deallocate the memory and destroy the objects
  for (int i = 0; i < 5; i++) {
    alloc.destroy(p + i);
  }
  alloc.deallocate(p, 5);

  return 0;
}
#endif

// TODO #define ALLOCATE
#ifdef ALLOCATE
//! Create my custom allocator
//! Will not work on Windows - only POSIX co
#include <unistd.h>
#include <sys/mman.h>
#include <stdexcept>

template <typename T>
class my_allocator
{
public:
    typedef T value_type;

    my_allocator() noexcept {}
    template <typename U> my_allocator(const my_allocator<U>&) noexcept {}

    T* allocate(std::size_t n)
    {
        if (n > std::size_t(-1) / sizeof(T))
            throw std::bad_alloc();

        void* p = mmap(nullptr, n * sizeof(T), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        if (p == MAP_FAILED)
            throw std::bad_alloc();

        return static_cast<T*>(p);
    }

    void deallocate(T* p, std::size_t n) noexcept
    {
        munmap(p, n * sizeof(T));
    }
};

template <typename T, typename U>
bool operator==(const my_allocator<T>&, const my_allocator<U>&) noexcept
{
    return true;
}

template <typename T, typename U>
bool operator!=(const my_allocator<T>&, const my_allocator<U>&) noexcept
{
    return false;
}
#endif