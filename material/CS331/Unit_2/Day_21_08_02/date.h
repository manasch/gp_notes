#ifndef DATE_H
#define DATE_H
class Date
{
	private:
	int dd_;
	int mm_;
	int yy_;
	public:
	explicit Date(int dd = 1, int mm = 1, int yy = 1970);
	friend ostream& operator<<(ostream&, const Date&);
};

#endif
