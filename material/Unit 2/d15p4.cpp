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
  Stack<double> s2;

  // assign stack of elements of type T2
  s2 = s1;
  return 0;
}
