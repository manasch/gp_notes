#include <iostream>
using namespace std;
#include <cstdlib>

int main()
{
#if 0
	int *p;
	p = (int *)malloc(sizeof(int) * 5);
	// ...
	free(p); // book keeping : used to find the size of the block to be de_allocated
#endif

	int *p;
	p = new int(25); // may not use book keeping 
	// new operator
	//		allocates memory : operator new
	//		initialization
	
	// ...
	delete p; // may or may not use book keeping
	// delete operator
	//		de-initialization : operator delete
	//		deallocates memory
	
	int *q;
	q = new int[4]{11, 22, 33, 44};
	// new [] operator
	//	allocates memory : operator new
	//	initializes each variable in a loop
	
	delete [] q; // uses book keeping
	// delete [] operator
	//	de-initializes each variable in a loop
	//	de-allocates memory : operator delete
	
	
	
	
	
	
	
			
}
