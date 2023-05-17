
#include<algorithm> // contains find()
#include<iostream>
#include<cassert>
#include<iterator>
template<class T>
class slist {
public:
/*Some types of the class get public names. Then it is possible to use them outside
the class without knowing the implementation.
*/
typedef T value_type;
typedef ptrdiff_t difference_type;
typedef T* pointer;
typedef T& reference;
// etc. see text
slist() : firstElement(0), Count(0) {}
/*copy constructor, destructor and assignment operator are omitted! The implementation of push_front() creates a new list element and inserts it at the beginning
of the list:
*/
void push_front(const T& Datum) { // insert at beginning
firstElement = new ListElement(Datum, firstElement);
++Count;
}
private:
struct ListElement {
INTERNAL FUNCTIONING 11
T Data;
ListElement *Next;
ListElement(const T& Datum, ListElement* p)
: Data(Datum), Next(p) {}
};
ListElement *firstElement;
size_t Count;
public:
class iterator {
public:
typedef std::forward_iterator_tag iterator_category;
typedef T value_type;
typedef T* pointer;
typedef T& reference;
typedef size_t size_type;
typedef ptrdiff_t difference_type;
iterator(ListElement* Init = 0)
: this(Init){}
T& operator*() { // dereferencing
return this->Data;
}
const T& operator*() const { // dereferencing
return this->Data;
}
iterator& operator++() { // prefix
if(this) // not yet arrived at the end?
this = this->Next;
return *this;
}
iterator operator++(int) { // postfix
iterator temp = *this;
++*this;
return temp;
}
bool operator==(const iterator& x) const {
return this == x.this;
}
bool operator!=(const iterator& x) const {
return this != x.this;
}
private:
ListElement* this; // pointer to this element
}; // iterator
/*As can be seen above, in the postfix variation of the ++ operator, the copy constructor is needed for initialization and return of temp. For this reason, the prefix
variation should be preferred where possible. Some methods of the slist class
use the iterator class:
*/
iterator begin() const { return iterator(firstElement);}
iterator end() const { return iterator();}
};
 
int main() {
const int count = 100;
slist<int> aContainer; 
for(int i = count; i >= 0; --i) { // fill the container with
aContainer.push_front(2*i); // even numbers
}
int Number = 0;
while(Number != -1) {
std::cout << " enter required number (-1 = end):";
std::cin >> Number;
if(Number != -1) {
// use of container methods:
slist<int>::iterator Position =
std::find(aContainer.begin(),
aContainer.end(), Number);
if(Position != aContainer.end())
std::cout << "found at position "
<< (Position - aContainer.begin())
<< std::endl;
else
std::cout << Number << " not found!"
<< std::endl;
}
}
}
