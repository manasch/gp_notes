#include <iostream>
using namespace std;
#include "date.h"

Date::Date(int dd, int mm , int yy )
: dd_(dd), mm_(mm), yy_(yy)
{
}

ostream& operator<<(ostream& o , const Date& d)
{
	return o << d.dd_ << "-" << d.mm_ << "-" << d.yy_;
}
