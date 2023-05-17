#include<iostream>
using namespace std;
// we can make a template parameter as a 
// friend as long as it is a valid type 
// it is ignored otherwise
template<typename T>
class Box {
    public:
    friend T;
    void set() { this->data = 10;}
    private:
   
    int data;
};

class Apple {
public:
    void func(Box<Apple> &box) {
        // Access private data member of Box
        cout << box.data << endl;
    }
};

int main() {
    Box<Apple> box;
    box.set();
    Apple a;
    a.func(box);
    // This is ignored 
    Box<int> boxy;
    boxy.set();
    return 0;
}
