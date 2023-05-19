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

void Person::disp()
{
	cout << "name : " << name_ << "\tage : " << age_ << "\n";
}

Person::Person(char *name, int age)
: name_(new char[strlen(name) + 1]), age_(age)
{
	strcpy(name_, name);
}

Person::Person()
: name_(new char[1]), age_(0)
{
	strcpy(name_, ""); // name_[0] = '\0';
}

void Person::operator=(const Person& rhs)
{
	delete[] this->name_;
	this->name_ = new char[strlen(rhs.name_)  + 1];
	strcpy(this->name_,rhs.name_);
	age_ = rhs.age_;  // this->age_ = rhs.age_;
}

Person::~Person()
{
	delete [] name_;
}


