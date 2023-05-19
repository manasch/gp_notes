### Unit 1

Q1 Write a template function called `displayType` that displays the type of the provided argument. Specialize this template function for `char`, `long`, and `bool` types to display a custom message for each type.

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
void displayType(T value) {
    cout << typeid(value).name() << endl;
}

template <>
void displayType(char value) {
    cout << "Specialized for char" << endl;
}

template <>
void displayType(long value) {
    cout << "Specialized for long" << endl;
}

template <>
void displayType(bool value) {
    cout << "Specialized for bool" << endl;
}

int main() {
    int a;
    float b;
    char c;
    long d;
    bool e;
    displayType(a);
    displayType(b);
    displayType(c);
    displayType(d);
    displayType(e);

    return 0;
}
```

Q4 Implement a template function called `areEqual` that checks if two arrays of the same type and size are equal. Use both type and non-type template parameters to define this function.

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T, size_t N>
bool areEqual(const T (&arr1)[N], const T (&arr2)[N]) {
    for (int i = 0; i < N; ++i) {
        if (arr1[i] != arr2[i])
            return false;
    }

    return true;
}

int main() {
    int arr1[] = {1, 3, 4};
    int arr2[] = {1, 3, 4};
    int arr3[] = {3, 4, 5};
    cout << boolalpha;
    cout << areEqual(arr1, arr2) << endl;
    cout << areEqual(arr2, arr3) << endl;
    return 0;
}
```

### Unit 2

Q1 Create a generic `AbstractBase` template class with a single pure virtual function called `getClassName` that returns a string representing the class name. Then, create a derived template class `ConcreteDerived` that inherits from `AbstractBase` and overrides the `getClassName` function to return its own class name. Demonstrate the usage of both classes.

```cpp
#include <string>
#include <iostream>
#include <typeinfo>

template<typename T>
class AbstractBase {
public:
    virtual std::string getClassName() const = 0;
};

template<typename T>
class ConcreteDerived : public AbstractBase<T> {
public:
    std::string getClassName() const {
        return typeid(T).name();
    }
};

class MyClass {};

int main() {
    ConcreteDerived<MyClass> obj;
    std::cout << obj.getClassName() << std::endl; // Output: 7MyClass
    
    return 0;
}
```


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