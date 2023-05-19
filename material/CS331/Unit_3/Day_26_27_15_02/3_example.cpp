#include <iostream>
using namespace std;
// T should support:
//		default ctor
//		dtor
//		copy ctor
//		copy assignment op
template <typename T> class Stack
{
  private:
    T *sp_;
    T *p_;
    int n_;

  public:
    explicit Stack(int n);
    ~Stack() { delete[] p_; }
    Stack(const Stack<T> &) = delete;
    Stack<T> &operator=(const Stack<T> &) = delete;
    void push(T key);
    T pop() { return *--sp_; }
};

template <typename T> void Stack<T>::push(T key) { *sp_++ = key; }

template <typename Q> Stack<Q>::Stack(int n) : n_(n), p_(new Q[n]), sp_(nullptr)
{
    sp_ = p_;
}

class MyNum
{
  private:
    int n_;

  public:
    MyNum(int n = 0) : n_(n) {}
    operator int() { return n_; }
};
int main()
{
#if 1
    Stack<int> s(10);
    s.push(100);
    s.push(200);
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
#endif
#if 1
    Stack<double> s1(10);
    s1.push(2.5);
    s1.push(3.6);
    cout << s1.pop() << "\n";
    cout << s1.pop() << "\n";
#endif
#if 1
    Stack<MyNum> s2(10);
    s2.push(25);
    s2.push(36);
    cout << s2.pop() << "\n";
    cout << s2.pop() << "\n";
#endif
}
