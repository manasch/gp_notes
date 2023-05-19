#ifndef PERSON_H
#define PERSON_H
#if 0
// version 1
class Person
{
	private:
	char *name_;
	int age_;
	public:
	Person(char *, int);
	
	void disp();
};
#endif

// version 2
class Person
{
	private:
	char *name_;
	int age_;
	// bool is_array;
	public:
	Person(const char *, int);
	Person();
	// assignment 
	Person& operator=(const Person& rhs); // y.operator=(x)
	// copy ctor:
	//	initialization
	//	a) initialize with an existing object
	//	b) parameter passing by value
	//	c) return by value
	//	compiler provides a shallow copy - memberwise copy
	Person(const Person&);
	~Person();
	// make the object through which the call is made a const
	// *this : const
	void disp() const;
};
// single ctor with default values
// Person(char *= "", int = 0); // ???

#endif

