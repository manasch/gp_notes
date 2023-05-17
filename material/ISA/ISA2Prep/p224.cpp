template <typename T>
class A {
public:
  using value_type = T;

  template <typename U>
  class B {
  public:
    using value_type = U;

    void foo(A<U>::value_type t) {
      A<U> a;
      // implementation omitted
    }
  };
};

template <typename T>
void bar(typename A<T>::template B<int>& b) {
  typename A<T>::value_type x;
  // implementation omitted
}
/*
A) A<T>::value_type is the same as A<U>::value_type.
B) A<T>::value_type is not the same as A<U>::value_type.
C) A<U>::B<int> can be passed directly to bar().
D) A<T>::B<int> can be passed directly to bar()

Answer: B) A<T>::value_type is not the same as A<U>::value_type, because T and U are independent template parameters. C) A<U>::B<int> cannot be passed directly to bar(), because the bar() function expects a reference to A<T>::B<int>. D) A<T>::B<int> can be passed directly to bar(), because bar() expects a reference to A<T>::B<int> and B<int> 
is a dependent nested template of A<T>.


*/