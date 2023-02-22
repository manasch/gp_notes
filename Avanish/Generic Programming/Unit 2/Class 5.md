#### Templates and friends

```c++
#include <iostream>

template <typename T>
class Accessor;

template <typename T>
class Container {
	private:
		T data;
	public:
		Container(T data): data(data) {}
		friend class Accessor<T>;
};

template <typename T>
class Accessor {
	public:
		static T getData(const Container<T> &c) {
		return c.data;
		}
};

int main() {
	Container<int> c(10);
	std::cout << Accessor<int>::getData(c) <<std::endl;
	return 0;
}
```
---
- Friends have access to private members as well
- Transitivity does not hold for friends
---
```c++
#include<iostream>

class A {  
    private:
     int x;
     friend class B;
    public:
     void setty() { x = 10;}

};
class B {
    public:
    void static print(const A &a)
    {
        std::cout << "X" << a.x;
    }
    private:
    friend class c;
};
class C:public B{      //changing B to public or private will change C's access to A
    public:
    // void static print(const A &a)
    // {
    //     std::cout << "X" << a.x;
    // }

 };
int main()
{
    A a;
    a.setty();
    B::print(a);
    C::print(a);
}
```
---
##### Golden rules for friends
- Not transitive.
- Not commutative.
- Not inheritable
---
##### Classes using different template arguements are ___different___ classes

```c++
template<typename T>
class Stack {
  private:
    int top;
  public:
    // ...

    // assign stack of elements of type T2
    template<typename T2>
    Stack<T>& operator= (Stack<T2> const& other) {
      top = other.top;
      // ...
      return *this;
    }

    // to get access to private members of Stack<T2> for any type T2:
    template<typename> friend class Stack;
};

int main() {
  Stack<int> s1;
  Stack<double> s2;   //notice the classes are different due to being int and double

  // assign stack of elements of type T2
  s2 = s1;
  return 0;
}
```
