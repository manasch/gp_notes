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

```cpp
template <typename T>
class Base{
public:
  void func1() const {
    std::cout << "func1()\n";
  }
  void func2() const {
    std::cout << "func2()\n";
  }
  void func3() const {
    std::cout << "func3()\n";
  }
};

template <typename T>
class Derived: public Base<T>{
public:
  using Base<T>::func2;              // (2)
  void callAllBaseFunctions(){

    this->func1();                   // (1) Make this implicit dependent
    func2();                         // (2) The expression using Base<T>::func2 
    Base<T>::func3();                // (3) Fully qualify

  }
};
```

- Need to scope it in one of those 3 ways.

Can have a specialized base class.
```cpp
template<typename T>
class Base {
	public:
		void set(const T& val) {data = val;}
		T get() const {return data};
	private:
		T data;
};

template<typename U>
class Derived : public Base<int> {
	public:
		void setDerived(const U& val) {derived_data = val;}
		U getDerived() const {return derived_data;}
		int getBase() const {return Base<int>::get();}
		void setBase(const int& val) {Base<int>::set(val);}
	private:
		U derived_data;
}
```

> Also possible to inherit from another template provided that the template is a class.

```cpp
class Base {
	//..
};

template<typename T>
class Derived : public T {
	//..
};
```

> Templatized derived class can inherit for a non-templatized base class

```cpp
#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  void foo() { std::cout << "Base" << std::endl; }
};

template <typename T>
class Derived : public Base<T> {
 public:
  void foo() { std::cout << "Derived" << std::endl; }
};

int main() {
  Derived<int> d;
  d.foo();
  
  Base<int> *p = &d;
  p->foo();
  return 0;
}
```

- This will give `Derived` and `Base`, this is because the derived class is just hiding the base class' implementation of the function. If the base class function foo is defined as `virtual` and then overrided in the derived class, then both these calls will give `Derived`
---

### Composition and Constructors

> Composed classes should manually delete the data it is composed of with the help of the destructor, as upon the deletion of the main class, the composed classes destructor don't get called.

> Can also delegate the destructor part to a shared_ptr which will take care of it for you.

```cpp
    std::vector<std::shared_ptr<Person>> people;
    std::vector<std::shared_ptr<House>> houses;
```

Shallow vs Deep copy constructor

```cpp
  C(const C &obj) {
    x = obj.x;
    std::cout << "Shallow Copy Constructor called" << std::endl;
  }

  C(const C &obj) {
    x = new int;
    *x = *obj.x;
    std::cout << "Deep Copy Constructor called" << std::endl;
  }
```

---

### Template and Friends

- If a class declares something as a friend, it can access that specific class' private members.
- A friend of a friend can't access the main guy's class. {A -> B -> C} C can't access A's private member.
- Though if C inherits from B, it can access A's private members.
- A friend template class must be defined.
- Can have the same class be it's own friend to access private members of the same class but different instances.
- If a template is a friend, then even it's specializations are considered friends.
- A template parameter can also be made a friend as long as it's a valid type.
```cpp
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
```

class friends:
```cpp
friend class B<T>;

template<typename T>
friend class B;
```

function friends:
```cpp
friend void func<>();
```

### Templates and Nested Classes
---

- Outer class can't access inner class' private members, inner class can access outer class' private members if you pass the instance of the outer class to the inner class.
- Inner classes can also have a life of their own, just gotta fully qualify it.
```cpp
    Outer::Inner1 inner1;
    inner1.value1 = 42;
    inner1.printValue1();
```
- Templatized nested classes are also possible.

### Dependent and Non-Dependent
---

- Non-Dependent datatypes are those which are not dependent on the template type.
- These are known at compile time.
- `using x = y`, Have to use `typename`. Basically when using aliases. Not needed during inheritance.
```cpp
struct dictionary_traits
{
    using key_type = int;
    using map_type = std::map<key_type, std::string>;
    static constexpr int identity = 1;
};
template <typename T> //* T is a type of type class
struct dictionary :T::map_type      //! Funny I dont need it here [1]
{
    int start_key { T::identity };   //! Nothing special here [2]
    typename T::key_type next_key;   //! Back to my old tricks  [3]
};
int main()
{
    dictionary<dictionary_traits> d;
}
```

- Have to specify when a funcition is a template
```cpp
template <typename T>
struct base_parser
{
   template <typename U>
   void init()
   {
      std::cout << "init\n";
   }
};
template <typename T>
struct parser : base_parser<T>
{
    void parse() {
        base_parser<T>::template init<int>();
        std::cout << "parser\n";
    }
}
```

- For template specialization, the name lookup is done at the call, so at the end. Hence the order in which you define the structures doesn't matter. But for regular functions, the name lookup is done within the class and so if the function isn't present in the lookup, it won't choose that.

```cpp
void handle(double value)  
//* [2] handle(double) definition
{
   std::cout << "processing a double: " << value << '\n';
}
template <typename T>
struct parser              
//* [3] template definition
{
   void parse()
   {
      handle(42);          
      //! [4] non-dependent name
   }
};
void handle(int value)    
 //* [5] handle(int) definition
{
   std::cout << "processing an int: " << value << '\n';
}
```

- Name lookup happens at `[4]`

```cpp
struct handler          
//* [1] template definition
{
   void handle(T value)
   {
      std::cout << "handler<T>: " << value << '\n';
   }
};
template <typename T>
struct parser          
 //* [2] template definition
{
   void parse(T arg)
   {  //! [3] dependent name
      //! It does not do a namelookup here 
      //! but only at the point parser is instantiated
      //! which happens in [6]
      arg.handle(42);   

   }
};
template <>
struct handler<int>    
//* [4] template specialization
{
   void handle(int value)
   {
      std::cout << "handler<int>: " << value << '\n';
   }
};
```

- Name lookup happens when called in the main func
---
---

# Unit - 3
---

> Function objects (and lambdas) tend to be faster than function arguments.

wrt policy for algorithms.

- STL doesn't check for safety. Only the bare minimum necessary stuff. Which is how it's fast.

### Containers
---

Types of containers:

- Sequence
- Associative

Sequence has lists, arrays, vector..
Associative has maps and sets.

> Stacks and queues are known as container adaptors.

Associative

- By default use the `<` operator to sort.
- Typically implemented as binary trees.

### Iterators
---

Declare iterator as such
```cpp
set<int>::iterator it;
vector<int>::iterator it;
```

map iterators would work on pairs
```cpp
std::pair<int, int>
```

`std::find` return an iterator at the location it found or the end of the container.
```cpp
vector<int>::iterator it = std::find(vec.begin(), vec.end(), elemToFind);
```


`std::list` can't perform normal iterator addition on this.

### Functors
---

Functors are class objects that behave like functions. It requires `()` operator to be overloaded. Can maintain state, and are sometimes faster, the difference between this and a regular function.

```cpp
class MyFunctor {
public:
	MyFunctor(int x) : value_(x) {}

	// Only function present
	int operator()(int x) {
		return x * value_;
	}
private:
	int value_;
};
```

Usually work with
	- Function pointers
	- Lambda functions
	- Functors

```cpp
// Using a function object
class AddOne {
public:
    template <typename T>
    void operator()(T& t) const {
        t += 1;
    }
};

// Using an ordinary function
template <typename T>
void addOne(T& t) {
    t += 1;
}
```

Functors can be used like this
```cpp
template<typename T>
class Adder {
public:
    T operator()(T x, T y) const {
        return x + y;
    }
};

int main() {
	Adder<int>()(1, 2);
	// or
	Adder<int> a;
	a(1, 2);
}
```

### Type Traits
---

- Compile time meta function.
```cpp
#include<type_traits>

template<typename T>
void foo(T val) {
	if (std::is_integral<T>::value) {
		//..
	}
}
```

```cpp
struct A {
	A(const A&) = delete; // Indicates that the copy constructor is deleted, no other object can make copies of this object.
	~A() noexcept; // Indicates that the destructor will not throw any exceptions.
}
```

if `noexcept(false)` is used that means the destructor can throw exceptions making it potentially unsafe hence `is_destructible` will give false.

> `find_if` used multiple times is faster than `count_if`

SFINAE can be implemented using `enable_if`.
or otherwise one classic example.

```cpp
template<typename T>
struct HasFooMethod {
  template<typename U>
  static auto test(int) -> decltype(std::declval<U>().foo(), std::true_type());
  
  template<typename U>
  static std::false_type test(...);

  static constexpr bool value = decltype(test<T>(0))::value;
};
```
This creates a test function to call and check if T has a foo method. Upon failure it doesn't crash, but just silently removes it from the list of overloaded functions that can be called by T.

---
---

# Unit - 4
---

### Template Metaprogramming

- Metaprogramming is the writing of computer programs thar write or manipulate other programs
- Uses template instantiation to drive compile-time evaluation.

RTTI - Run-Time Type Identification is a mechanism where an object's data type can be found out at run time and this is only available to those classes that have atleast one virtual function. (So is it similar to reflection ?)

So Reflection is the ability for a piece of code to examine and modify its own structure, behavior and metadata at runtime.

`decltype(expr)` is a keyword that is used to find the type of an expression at compile-time.

- Metafunction: is essentially a template that takes in template parameters and returns a type or value at compile time.

SFINAE in use
```cpp
template<typename T>
typename std::enable_if<has_addition_operator<T>::value, T>::type add(T a, T b) {
	return a + b;
}

```

- Constexpr is used to indicate that a function or object can be evaluated at compile-time. The compiler tries its best to evaluate the expression at compile-time.

---

### Virtual Functions

```cpp
#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  void foo() { std::cout << "Base" << std::endl; }
};

template <typename T>
class Derived : public Base<T> {
 public:
  void foo() { std::cout << "Derived" << std::endl; }
};

int main() {
  Derived<int> d;
  d.foo();
  
  Base<int> *p = &d;
  p->foo();
  return 0;
}
```

This is early binding, the Derived foo hides the base foo, but if the base foo is virtual and overrided then both print Derived which is late binding.

> Virtual destructors are critical, could lead to dangerous code if not.

CRTP is done to perform compile time binding. CRTP stands for Curiously Recurring Template Pattern.

```cpp
template <typename Derived>
class Shape {
public:
	void draw() {
		static_cast<Derived*>(this)->draw_impl();
	}
};

class Circle : public Shape<Circle> {
public:
	void draw_impl() {
		cout << "Drawing a circle" << endl;
	}
};

class Square : public Shape<Square> {
public
	void draw_impl() {
		cout << "Drawing a square" << endl;
	}
}

```

Types of folds

-   Unary right fold: (pack op ...) --> (1 + (2 + (3 ....(n-1 + n))))
-   Unary left fold: (... op pack) --> (((1 + 2) + 3) ...)
-   Binary right fold: (pack op ... op init) --> (arg1 op (arg2 ( op arg3 ...)))
-   Binary left fold: (init op ... op pack) --> ((((init op arg1) op arg2) op arg3))

---
---
