/*
here is some erronous code */
/*template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
List<elemType>();
List<elemType>(const List<elemType> &);
List<elemType>& operator=(const List<elemType> &);
~List();
void insert(ListItem *ptr, elemType value);
private:
ListItem *front, *end;
};*/
/* Correct it 
The ListItem class is a simple container class that holds a value of type elemType and a
pointer to the next item in the list.
The List class is a singly linked list implementation that holds a pointer to the front and end of the list and 
it can have the functionality to insert a new element to the list and copy, assign and delete the list.

*/
template <typename elemType>
class ListItem {
public:
    ListItem(elemType val) : value(val), next(nullptr) {}
    elemType value;
    ListItem<elemType> *next;
};

template <typename elemType>
class List {
public:
    List() : front(nullptr), end(nullptr) {}
    List(const List &other) { 
        // copy constructor code
    }
    List& operator=(const List &other) {
        // assignment operator code
    }
    ~List() {
        // destructor code
    }
    void insert(ListItem<elemType> *ptr, elemType value) {
        // insert code
    }
private:
    ListItem<elemType> *front, *end;
};
int main() {
    List<int> myList;
    ListItem<int> *ptr = new ListItem<int>(10);
    myList.insert(ptr,20);

    return 0;
}
