#include <iostream>
using namespace std;

#include <vector>

int main()
{
	vector<int> v{11, 22, 33, 44};
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	v.push_back(55);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	v.push_back(66);
	v.push_back(77);
	v.push_back(88);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	v.push_back(99);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	
}
// increase in size :
// a) inefficient : copying of elements; release of resource
// b) invalidates pointers, references and iterators

