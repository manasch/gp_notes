#include <iostream>
using namespace std;
#include <cstring>

class MyStr
{
  public:
    MyStr(const char *s) : s_(new char[strlen(s) + 1]) { strcpy(s_, s); }
    ~MyStr() { delete[] s_; }
    MyStr(const MyStr &rhs) : s_(new char[strlen(rhs.s_) + 1])
    {
        strcpy(s_, rhs.s_);
    }
    MyStr &operator=(const MyStr &rhs)
    {
        if (this != &rhs)
        {
            delete[] s_;
            s_ = new char[strlen(rhs.s_) + 1];
            strcpy(s_, rhs.s_);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &o, const MyStr &s);

  private:
    char *s_;
};
ostream &operator<<(ostream &o, const MyStr &s) { return o << s.s_ << "\n"; }

void myswap(MyStr &lhs, MyStr &rhs)
{
    MyStr temp(lhs); // copy ctor
    lhs = rhs;       // copy assignment op
    rhs = temp;
}

int main()
{
    MyStr a("amar");
    MyStr b("bharat");
    cout << a << b;
    myswap(a, b);
    cout << a << b;
}
