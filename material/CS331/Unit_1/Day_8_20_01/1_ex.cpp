#include <iostream>
using namespace std;
#include <cstring>

template<typename value_t>
bool eq(value_t x, value_t y)
{
	return x == y;
}
// specialization
template<>
bool eq<char*>(char* x, char* y)
{
	cout << "comparing char*\n";
	return strcmp(x, y) == 0;
}
int main()
{
	char a[] = "pes";
	char b[] = "pes";
	cout << boolalpha;
	cout << "res : " << eq(65, 65) << "\n";
	cout << "res : " << eq('A', 'A') << "\n";
	
	cout << "res : " << eq(a, b) << "\n";
}


// equality:
// int *p;
// int *q;
// initialized (assume)
//	reference or pointer sematics : p == q
//	value semantics : *p == *q

