// Implement the acquire and print functions for arrays, vectors, queues and stacks 
// 1 point for each function
#include<iostream>
#include<array>
#include<vector>
#include<queue>
#include<stack>
template < typename T = int, typename Container = std::array < T, 5 >>
  class Acquisition
{
public:
Acquisition (size_t n = 5, Container c = Container ()):num_values (n),
    container (c)
  {
  }

  // Function to acquire and store values in the container
  void
  acquire ()
  {
    
  }

  // Function to print the values stored in the container
  void
  print ()
  {
    
  }

private:
  size_t num_values;
  Container
    container;
};

int
main ()
{
  // Test with default values (num_values = 5, container = std::array<int, 3>)
  Acquisition <> test1;
  test1.acquire ();
  test1.print ();

  // Test with custom values (num_values = 3, container = std::vector<int>)
  Acquisition < int,
  std::vector < int >>
  test2 (3);
  test2.acquire ();
  test2.print ();

  // Test with custom values (num_values = 3, container = std::queue<int>)
  Acquisition < int,
  std::queue < int >>
  test3 (3);
  test3.acquire ();
  test3.print ();

  // Test with custom values (num_values = 3, container = std::stack<int>)
  Acquisition < int,
  std::stack < int >>
  test4 (3);
  test4.acquire ();
  test4.print ();

  return 0;
}
