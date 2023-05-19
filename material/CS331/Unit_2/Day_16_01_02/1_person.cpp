#include <iostream>
using namespace std;
#include "1_person.h"
#if 0
// version 1
void Person::disp()
{
	cout << "name : " << name_ << "\tage : " << age_ << "\n";
}

Person::Person(char *name, int age)
: name_(name), age_(age)
{
}
#endif

// version 2
#include <cstring>

void Person::disp() const
{
	cout << "name : " << name_ << "\tage : " << age_ << "\n";
}

Person::Person(const char *name, int age)
: name_(new char[strlen(name) + 1]), age_(age)
{
	strcpy(name_, name);
}

Person::Person()
: name_(new char[1]), age_(0)
{
	strcpy(name_, ""); // name_[0] = '\0';
}

Person::Person(const Person& rhs)
: name_(new char[strlen(rhs.name_) + 1]), age_(rhs.age_)
{
	strcpy(name_, rhs.name_);
}

// three ways of return:
//	return by value
//	return by ref : efficient; life time matters
//  	(x = y) = z ok
//	return by ref to const : efficient ; life time matterns
//		non-modifiable lvalue
//		(x = y) = z should be an error

// deep copy
Person& Person::operator=(const Person& rhs)
{
// self assignment
	if(this != &rhs)
	{
		delete[] this->name_;
		this->name_ = new char[strlen(rhs.name_)  + 1];
		strcpy(this->name_,rhs.name_);
		age_ = rhs.age_;  // this->age_ = rhs.age_;
	}
	return *this;
}

Person::~Person()
{
	delete [] name_;
}
/*
//life time matters
// returns a ref to a; a dies at the end of the block
// ends up in dangling reference
// To return by ref, referrent should have life in the caller
int& foo()
{
	int a(10);
	return a;;
}
*/










