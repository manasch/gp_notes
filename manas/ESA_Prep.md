# Unit - 1
---

#### Introduction
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

