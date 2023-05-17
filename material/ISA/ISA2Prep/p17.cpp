#include<iostream>
template <typename T, T (*Func)(T)> //! [1] Fails here
class MyTemplateClass {
public:
  T getValue(T value) { 
    return Func(value); //![2] Fails here
  }
};
//![3] should have defined ahead
int square(int x) { 
  return x * x;
}
int main() { }
//! Which of the above statements are WRONG
