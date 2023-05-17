#include <algorithm>
#include <iostream>
#include <cassert>
#include <iterator>
template<class T>
class slist {
public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    slist() : firstElement(nullptr), Count(0) {}

    void push_front(const T& Datum) {
        firstElement = new ListElement(Datum, firstElement);
        ++Count;
    }

private:
    struct ListElement {
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

        iterator(ListElement* Init = nullptr) : ptr(Init) {}

        T& operator*() { // dereferencing
            return ptr->Data;
        }

        const T& operator*() const { // dereferencing
            return ptr->Data;
        }

        iterator& operator++() { // prefix
            if (ptr) { // not yet arrived at the end?
                ptr = ptr->Next;
            }
            return *this;
        }

        iterator operator++(int) { // postfix
            iterator temp = *this;
            ++*this;
            return temp;
        }

        bool operator==(const iterator& x) const {
            return ptr == x.ptr;
        }

        bool operator!=(const iterator& x) const {
            return ptr != x.ptr;
        }

    private:
        ListElement* ptr; // pointer to this element
    }; // iterator

    iterator begin() const { return iterator(firstElement); }
    iterator end() const { return iterator(nullptr); }
};

int main() {
    const int count = 100;
    slist<int> aContainer;
    for (int i = count; i >= 0; --i) {
        aContainer.push_front(2 * i); // fill the container with even numbers
    }

    int Number = 0;
    while (Number != -1) {
        std::cout << "Enter required number (-1 = end): ";
        std::cin >> Number;
        if (Number != -1) {
            slist<int>::iterator Position = std::find(aContainer.begin(), aContainer.end(), Number);
            if (Position != aContainer.end()) {
                std::cout << "Found at position " << std::distance(aContainer.begin(), Position) << std::endl;
            } else {
                std::cout << Number << " not found!" << std::endl;
            }
        }
    }
}
