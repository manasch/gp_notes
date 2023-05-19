#include <iostream>
using namespace std;

class Stack
{
  private:
    int *sp_;
    int *p_;
    int n_;

  public:
    explicit Stack(int n) : n_(n), p_(new int[n]), sp_(nullptr) { sp_ = p_; }
    ~Stack() { delete[] p_; }
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;
    void push(int key) { *sp_++ = key; }
    int pop() { return *--sp_; }
};

int main()
{
    Stack s(10);
    s.push(100);
    s.push(200);
    // cout << s.pop() << "\t" << s.pop() << "\n"; // undefined
    cout << s.pop() << "\n";
    cout << s.pop() << "\n";
}

// cout << s.pop() << s.pop()
// operator<<(operator<<(cout, s.pop()), s.pop())

// printf("%d %d", pop(&s), pop(&s)); // undefined
// printf("%d %d %d", a++, --a, ++a); // ??? Terrible

// The C puzzle book : Feuer
