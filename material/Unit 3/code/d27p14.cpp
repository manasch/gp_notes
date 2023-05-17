#include<vector>
using namespace std;
int main()
{
vector<int> vec{1, 2, 3}; // vec contains [1, 2, 3] with capacity 3
vec.push_back(4); // push_back called with item 4

// Step 1: Check if there is enough memory
// Since vec has capacity 3 and size 3, there is not enough memory
// Allocate new memory with capacity 6
int* new_memory = new int[6];

// Step 2: Add the new item to the end of the vector
// Copy the existing items to the new memory
new_memory[0] = vec[0]; // copy 1
new_memory[1] = vec[1]; // copy 2
new_memory[2] = vec[2]; // copy 3
new_memory[3] = 4;      // add 4 to the end

// Step 3: Destroy the old items in the original memory
// Destruct the existing items in vec
vec.~vector(); // call the destructor of vec

// Step 4: Deallocate the old memory
// Deallocate the memory previously used by vec
int* old_memory = new int[3]; // get the pointer to the old memory
std::copy(vec.begin(), vec.end(), old_memory); // copy the values to the old memory
delete[] old_memory; // deallocate the old memory

// Set the internal pointers and variables of vec to point to the new memory
vec._M_impl._M_start = new_memory;
vec._M_impl._M_finish = new_memory + 4;
vec._M_impl._M_end_of_storage = new_memory + 6;
}