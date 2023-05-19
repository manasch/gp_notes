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
    // move ctor : stealing resource
    // rhs (object passed as argument has some resource)
    // not required after this operation
    // steal the resource
    // ownership change

    MyStr(MyStr &&rhs) : s_(rhs.s_)
    {
        rhs.s_ = nullptr; // alternate : rhs.s_ refer to a null string
    }
    MyStr &operator=(MyStr &&rhs)
    {
        if (this != &rhs)
        {
            delete[] s_;
            s_ = rhs.s_;
            rhs.s_ = nullptr;
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
    MyStr temp(move(lhs)); // move ctor
    lhs = move(rhs);       // move assignment op
    rhs = move(temp);
}

int main()
{
#if 0
	MyStr a("amar");
	MyStr b(move(a));
	cout << "b : " << b << "\n";
	//cout << "a : " << a << "\n"; // undefined
#endif
#if 0
	MyStr a("amar");
	MyStr b("bharat");
	b = move(a);
	cout << "b : " << b << "\n";
#endif
    MyStr a("amar");
    MyStr b("bharat");
    cout << a << b << "\n";
    cout << "\n";
    myswap(a, b);
    cout << a << b << "\n";
}
