#### C++ inheritance

```c++
#include <iostream>
class Base{
private:
	void func() {
	std::cout << "func\n";
	}
}
class Derived:public Base{
public:
	void callBase() {
	func();
	}
}
int main() {
	Derived derived;
	derived.callBase();
	
}
```
---
```c++
#include <iostream>
template <typename T>
class Base{
private:
	void func() {
	std::cout << "func\n";
	}
}
class Derived:public Base{
public:
	void callBase() {
	func();
	}
}
int main() {
	Derived derived;
	derived.callBase();
	
}
```

---
---

```c++
class c;
c c1;
c2 = c1; //shallow copy
c2(c1);  //deep copy
```

---
When dealing with templates, we always look upwards first to check if it's already been defined (both methods and data), unless fully qualified.
