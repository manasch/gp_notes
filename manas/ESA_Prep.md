# Unit - 1
---

### Introduction
---

What does this do ?
```cpp
char (*ptr)[4];
```

This is a declaraion of a pointer to an array of characters of size 4.
```cpp
char a = {'a', 'b', 'c', 'd'};
char (*ptr)[4];
ptr = &a;

(*ptr)[0] // Will give 'a'
```

Using function pointers would look something like this.
```cpp
#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int main()
{
    int res;
    int (*ptr)(int, int); // Declaration of some pointer, in this case a function pointer.
    ptr = add;
    
    res = (*ptr)(10, 20);
    cout << res;
    return 0;
}
```

- When dealing with macros, make sure to enclose the action with ();

```cpp
#define INCR(X) (++(X)) // even though (++X) also works, this is better practice.
```

> `cout << boolalpha` is a manipulator that changes the output format of boolean values from int to text. (0 to false, 1 to int)

> `auto` is a compile-time mechanism.

- A pure type essentially refers to a class that has no instance variables (no non-static data members) and no member functions. Defines what to do and not how, implemented as an abstract class typically with pure functions.
- Pure virtual functions are just the function declaration in the parent class that has to be overridden by any subclass that wants to instantiate objects.
- Just plain virtual functions call also exist, they have implmentation whereas pure virtual functions don't have any implementation
```cpp
class Shape {
	public:
		virtual double area() const = 0;
		virtual double perimeter() const = 0;
};
```

- Pure functions is a function that doesn't modify any variable or state outside it's own scope, to declare a function pure, it can have `const`.
- Lambda functions are not pure

> `Currying` refers to partial application of a function.

---

### Something

- Initialization:
	- Copy
	- Direct
	- Uniform

```cpp
int a(10); // Direct
int b = 10; // Copy
int c[5] = {1, 2, 3, 4}; // Uniform
```

Copy creates new mem block, direct uses a reference to point to the prev memor

- Promotions:

Integer promotion: Integral to int, `char, signed char, unsigned char, short, unsigned short` all to `int`
Floating promotion: `float` to `double`
Standard or numeric conversions
Pointer conversion: Pointer to derived can be converted implicitly to pointer to its base

---

### Functions

Matching parameters

- Trivial conversions:
	- Array to pointer
	- Function pointer conversionV
	- Variable/pointer to const
- Integral: Refer [here](#Something)
- Floating: Refer [here](#Something)
- Standard: Integral to int, floating to double (basically the above two)

Unsafe conversion:
	Pointer to Pointer (int to double)

User defined conversion
```cpp
#include <iostream>

using namespace std;

class Time {
    int hour, min;
    public:
        Time(int t) {
            hour = t / 60;
            min = t % 60;
        }

        void display() {
            cout << hour << ":" << min;
        }
};

int main() {
    // Time T1(95);
    int dur = 95;

    Time t = dur;
    t.display();

    return 0;
}
```

Prints: `1:35`

---

### Something - 2

> If the result of an operation is in the variable of a programmer then it is l-value

```cpp
++a; // No temporary, L-value
a++; // Requires a temporary, R-value
```

- Void pointers can point to any data type and hence need to be type casted for use.

```cpp
void swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}
```

- Requires the size to be passed as well.

### Templates
---

They can be of three types
1. Type template: `template<typename T>`
2. Non-type template: `template<int m>`
3. Template-Template: `template<template<typename T>>`

Ex:
```cpp
template<typename T>
void foo(T t) {
	// Generic implmenetation
}

template<class T1, class T2>
class MyClass {
	public:
		void foo() {
			// Generic implmentation
		}
};

template<>
void foo<int>(int t) {
	// Fully specialized implmentation for int
}

template<class T>
class MyClass<T, int> {
	public:
		void foo() {
			// Partial specialized for T, int
		}
}
```

```cpp
#include<iostream>
using namespace std;
template <typename T>
T max(T lhs,T rhs) {
    cout << "T\n";
    return (lhs > rhs)? lhs : rhs;
}
double max(double lhs, double rhs) {
    cout << "Fun\n";
    return (lhs > rhs)? lhs : rhs;
}

int main() {
    ::max(10.5f, 5.5f); //  (1)
    ::max(10.5, 5.5);   // (2)
}
```

- When a template exists for the specific type, it chooses to instantiate a template rather than promote to the nearest available type.

- Explicit instantiation is when you give the compiler hints on what the template parameter should be during the call itself.
```cpp
template<typename T>
T myFunc(const T&p) {
	// implementation
}

int main() {
	auto res = myFunc<int>(10); // Explicitly instantiating for int. Type conversion also would occur here if required.
}
```

