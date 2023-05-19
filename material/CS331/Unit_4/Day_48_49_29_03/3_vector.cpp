#include <iostream>
using namespace std;

#include <vector>

int main()
{
	vector<int> v{11, 22, 33, 44};
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	v.reserve(20); // capacity >= reserve
	v.push_back(55);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	v.push_back(66);
	v.push_back(77);
	v.push_back(88);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	v.push_back(99);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	for(int i = 0; i < 10; ++i)
		v.push_back(i);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
	v.push_back(10);
	v.push_back(11);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << "\n";
		
}
