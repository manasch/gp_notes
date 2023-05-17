#include <iostream>
#include <list>

int main() {
    int i = 1;
    std::list<int> mylist = {5, 2, 9, 1, 3};
    std::list<int> otherlist = {4, 8, 6};
    std::cout << i++;
    otherlist.sort(); 
    //* The other list must be sorted for the merge to work
    mylist.merge(otherlist); 
    //* Now mylist contains {1, 2, 3, 4, 5, 6, 8, 9}
    mylist.push_front(0); 
    std::cout << i++;
    //* mylist now contains {0, 1, 2, 3, 4, 5, 6, 8, 9}
    mylist.pop_front(); 
    //* mylist now contains {1, 2, 3, 4, 5, 6, 8, 9}
    //* Remove elements that are equal to a given value
    mylist.remove(4); // mylist now contains {1, 2, 3, 5, 6, 8, 9}
    //* Remove elements for which a predicate is true
    mylist.remove_if([](int n) { return n % 2 == 0; }); // mylist now contains {1, 3, 5, 9}
    //* Reverse the order of elements in the list
    mylist.reverse(); // mylist now contains {9, 5, 3, 1}
    mylist.sort(); // mylist now contains {1, 3, 5, 9}
    //* Define a comparison object for sorting the list
    struct greater_than {
        bool operator()(int a, int b) const {
            return a > b;
        }
    };

    //* Sort the elements using the comparison object
    mylist.sort(greater_than()); // mylist now contains {9, 5, 3, 1}

    //* Splice the entire contents of another list before a given position
    std::list<int> anotherlist = {2, 4, 6, 8};
    mylist.splice(mylist.begin(), anotherlist); // mylist now contains {2, 4, 6, 8, 9, 5, 3, 1}
    //* anotherlist is now empty

    // *Splice a single element from another list before a given position
    mylist.splice(mylist.begin(), anotherlist, anotherlist.begin()); // mylist now contains {2, 4, 6, 8, 9, 5, 3, 1, 2}
    //* anotherlist is still empty
    //* Splice a range of elements from another list before a given position
    mylist.splice(mylist.begin(), anotherlist, anotherlist.begin(), anotherlist.end()); // mylist now contains {2, 4, 6, 8, 9, 5, 3, 1, 2, 4, 6, 8}
    //* anotherlist is still empty

    //* Remove consecutive duplicate elements from the list
    mylist.unique(); // mylist now contains {2, 4, 6, 8, 9, 5, 3,
    return 0;
}