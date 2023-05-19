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
    explicit Stack(int n) : n_(n), p_(new T[n]), sp_(nullptr) { sp_ = p_; }
    ~Stack() { delete[] p_; }
    Stack(const Stack<T> &) = delete;
    Stack<T> &operator=(const Stack<T> &) = delete;
    void push(T key) { *sp_++ = key; }
    T pop() { return *--sp_; }
};
// instantiate class template
// no implicit instantiation
// a) explicit instantiation
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
#if 0
	Stack<int> s(10);
	s.push(100);
	s.push(200);
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
#endif
#if 0
	Stack<double> s(10);
	s.push(2.5);
	s.push(3.6);
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
#endif
#if 1
    Stack<MyNum> s(10);
    s.push(25);
    s.push(36);
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
#endif
}
