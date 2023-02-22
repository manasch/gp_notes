```cpp
#include <iostream>

using namespace std;

template <typename T>
class C{
  public:
    void f() {
      cout << "Hel" << endl;
    }
};

int main() {
  C<int> x;
  //x.f();
  C<int> *p = 0;
  p->f();
}
```

- This still works and gives an output. You get "Hel" for both.

```cpp
template<typename T>
class C{
  public:
  C(T);
};

void candidate(C<double>);
void candidate(int) {}
//void candidate(double) {}

int main() {
  candidate(42);
  candidate(4.2);
}
```

- This one picks `C<double>` anyways for some reason, without checking int. Hence `C<>` is instantiated.
- The ordering does not matter as it still picks `C<double>`. Chooses the same even if `candidate(double)` is uncommented.
- If `void candidate(C<double>) {}` is done then it gets instantiated cuz of the defn itself. If it is done as it is given above, then it's cuz of `candidate(42)` instead of the function declaration.
- Both of them choose to go to the `int` defined function anyways.

```cpp
template <typename T>
class X {
  public:
  X *p;
  void f() {int i = 0;}
  void g() {int j = 0;}
};

int main() {
  X<int> *q;
  X<int> r;
  X<float> *s;
};
```

- Only instantiated because of `X<int> r`.
---
- Compiler implicitly instantiates a class templates if it has static members.
- The static method instantiation is done only when required though so it's still lazy.
- Not allocated memory though when the class template is used. Onlyl when first accessed.

```cpp
#include <iostream>

template <typename T>
class MyClass {
  public:
  static int counter;
  MyClass() {
    ++counter;
  }
};

template <typename T>
int MyClass<T>::counter = 0;

int main() {
  MyClass<int> a;
  MyClass<double> b;
  
  std::cout << MyClass<int>::counter << std::endl;
  std::cout << MyClass<double>::counter << std::endl;
  
  return 0;
}
```

```cpp
#include <iostream>

template<typename T>
class MyClass
{
  
  public: 
  static int counter;
  inline MyClass()
  {
    ++counter;
  }
  
};

/* First instantiated from: insights.cpp:16 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class MyClass<int>
{
  
  public: 
  static int counter;
  inline MyClass()
  {
    ++counter;
  }
  
};

#endif
/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class MyClass<double>
{
  
  public: 
  static int counter;
  inline MyClass()
  {
    ++counter;
  }
  
};

#endif


template<typename T>
int MyClass<T>::counter = 0;
#ifdef INSIGHTS_USE_TEMPLATE
int MyClass<int>::counter = 0;
#endif
#ifdef INSIGHTS_USE_TEMPLATE
int MyClass<double>::counter = 0;
#endif


int main()
{
  MyClass<int> a = MyClass<int>();
  MyClass<double> b = MyClass<double>();
  std::cout.operator<<(MyClass<int>::counter).operator<<(std::endl);
  std::cout.operator<<(MyClass<double>::counter).operator<<(std::endl);
  return 0;
}
```

- Output is `1 1`.

--- 
##### Variable Templates

```cpp
#include <iostream>

using namespace std;

constexpr double PI = 3.14159266535887832385L;
template <typename T>
T sphere_vol(T const r) {
    return 4 * PI * r * r * r / 3;
}

int main() {
    float v1 = sphere_vol(42.0f);
    double v2 = sphere_vol(42.0);
    
    cout << v1 << " " << v2 << endl;
}
```

- Apparently this was supposed to throw an error, but it did not, Assuming that it should throw and error because `PI` is by default `double`.
- `float` is just typecasted.
- Hence we use variable templates.
```cpp
#include <iostream>

using namespace std;

template <class T>
constexpr T PI = T(3.14159266535887832385L);

template <typename T>
T sphere_vol(T const r) {
    return 4 * PI<T> * r * r * r / 3;
}

int main() {
  double ans = sphere_vol(40.0f);
  
  cout << ans;
  return 0;
}
```

- Get a new `PI` value depending on the value sent to the function.

---

##### Inheritance

- Private methods and members aren't inherited.
- Inheritance can be done in 3 ways, `public`, `protected` and `private`.

|Access Specifier|Before|After|
|--|--|--|
|Public|Public|Public|
|Public|Protected|Protected|
|Public|Private|Inaccessible|

|Access Specifier|Before|After|
|--|--|--|
|Private|Public|Private|
|Private|Protected|Private|
|Private|Private|Inaccessible|

|Access Specifier|Before|After|
|--|--|--|
|Protected|Public|Protected|
|Protected|Protected|Protected|
|Protected|Private|Inaccessible|

---

- Templatized inheritance for some reason requires you to call derived methods using `this` keyword.
- The methods in the parent class need to be brought to scope
    - Implicit by using `this`
    - Bring it in scope `using Base<T>::func
    - Fully qualify `Base<T>::func()
