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

Specialization
> Functions can't be partially specialized.

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

> `int * &ref = ptr` is valid and `int & *ptr1 = ptr` is invalid.

### Template Arguements
---

- Default arguements
	- Class template, if default mentioned, all subsequent must be default as well.
	- Not the same for a function template. (but it doesn't work)
	- Not allowed in declarations of friend templates, or in explicit specialization of a function template.

Can have cascading defaults
```cpp
template<typename T, typename U = double> struct foo;
template<typename T = int, typename U> struct foo;
template<typename T, typename U> struct foo;
```

- The template arg type can also be inferred by the arguements passed. (for functions)
```cpp
template<typename T, typename U>
void add(T a, T b) {
	return a + b;
}

int main() {
	add(1, 2);
	add<double, int>(3.14, 2);
}
```

- Similarly it can be explicit and derived too
```cpp
template<typename T, int size>
void print_array() {};

int main() {
	int arr[] = {1, 2, 3, 4};
	print_array(arr);
	// or
	print_array<int, 4>(arr);
}
```

> Overloaded resolution ignores function template specialization, therefore the order matter.

```cpp
template<typename T>
void func(T) {
	//
}

template<typename T>
void func(T*) {
	//
}

template<> // function specialization don't have to do func<int> unlike for classes / structs
void func(T *) {
	//
}

int main() {
	int *p;
	func(p); // takes the specialization, but if the overloaded func was below the specialized one, then it would take the overloaded one.
}
```

---
---

# Unit - 2
---

### Instantiation

- Templates follow lazy instantiation, any methods in a class or struct isn't instantiated until and unless they are actually used.

```cpp
template<typename T>
class C{
  public:
  	C(T);
};

void candidate(C<double>);
void candidate(int) {};
void candidate(double) {};

int main() {
  candidate(41);
  //candidate(4.2);
  return 0;
}
```

- Here, `candidate(C<double>)` isn't even being used but the `double` for C is instantiated anyways.

- The compiler implicitly instantiates a class template that contains static members, those static members are not implicitly instantiated.
- It only instantiates the static member when it requires the static member definition.

> Static members / vars can't be defined within the class they have to done outside

```cpp
template<typename T>
class MyClass {
	static int counter;
	MyClass() {
		++counter;
	}
};

// Probably because each static member needs a unique definition
template<typename T>
int MyClass<T>::counter = 0;

// but if the static var is const, only then it can be instantiated inside

template<typename T>
class MyClass {
	static const int count = 10;
	//
};
```

- Here the static member for int isn't instantiated as it isn't used.
```cpp
#include <iostream>
using namespace std;

template <typename T>
class MyClass {
public:
    static int my_static_member;
};

template <typename T>
int MyClass<T>::my_static_member = 42;

int main() {
    MyClass<int> obj;
    
    cout << MyClass<double>::my_static_member << endl;
}
```

> Even variables can be templateized

```cpp
template<class T>
constexpr T pi = T(3.141592);
```

---

### Inheritance

