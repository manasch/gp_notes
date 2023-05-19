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
	Person(char *, int);
	Person();
	~Person();
	void disp();
};
// single ctor with default values
// Person(char *= "", int = 0); // ???

#endif

