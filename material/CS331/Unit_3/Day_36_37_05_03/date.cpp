#include <iostream>
using namespace std;
#include "date.h"

Date::Date(int dd, int mm, int yy) : dd_(dd), mm_(mm), yy_(yy) {}

ostream &operator<<(ostream &o, const Date &d)
{
    return o << d.dd_ << "-" << d.mm_ << "-" << d.yy_;
}
// int a = 10;
// ++ ++ a; // ???

// pre incr
Date &Date::operator++()
{
    // logic to incr the date ...
    ++dd_; // please complete the implementation of logic
    return *this;
}

// post incr
// 2 extra objects; 2 ctor and 2 dtor
Date Date::operator++(int)
{
    /*
            Date temp(*this);
            // logic to incr the date ...
            ++dd_; // please complete the implementation of logic
            return temp;
    */
    Date temp(*this);
    // call pre
    ++*this;
    return temp;
}

#if 0
Date::operator int() const
{
	return dd_;
}
#endif

bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.yy_ < rhs.yy_)
        return true;
    if (lhs.yy_ == rhs.yy_ && lhs.mm_ < rhs.mm_)
        return true;
    if (lhs.yy_ == rhs.yy_ && lhs.mm_ == rhs.mm_ && lhs.dd_ < rhs.dd_)
        return true;
    return false;
}
#if 1
bool operator==(const Date &lhs, const Date &rhs)
{
    return lhs.yy_ == rhs.yy_ && lhs.mm_ == rhs.mm_ && lhs.dd_ == rhs.dd_;
}

bool operator!=(const Date &lhs, const Date &rhs) { return !(lhs == rhs); }
#endif
