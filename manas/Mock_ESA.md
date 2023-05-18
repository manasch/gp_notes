### Unit 2

Q3 Create a template class `SingleValue` that stores a single value of any type. Implement a template friend function `exchangeContents` that swaps the contents of two `SingleValue` objects. Demonstrate the usage of the `exchangeContents` function.  

```cpp
#include <iostream>

using namespace std;

template <typename T>
class SingleValue {
    private:
        T data;
    public:
        SingleValue(T val) : data(val) {};

        template <typename U>
        friend void exchangeContents(SingleValue<U>& s1, SingleValue<U>& s2);

        void displayData() {
            cout << data << endl;
        }
};

template <typename U>
void exchangeContents(SingleValue<U>& s1, SingleValue<U>& s2) {
    U temp;
    temp = s1.data;
    s1.data = s2.data;
    s2.data = temp;
}

int main() {
    SingleValue<int> a(10), b(20);

    cout << "Initial Values:" << endl;
    a.displayData();
    b.displayData();

    exchangeContents(a, b);

    cout << "After exchanging:" << endl;
    a.displayData();
    b.displayData();
    return 0;
}
```