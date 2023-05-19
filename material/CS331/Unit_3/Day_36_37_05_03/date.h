#ifndef DATE_H
#define DATE_H

class Date
{
  private:
    int dd_;
    int mm_;
    int yy_;

  public:
    Date(int dd = 1, int mm = 1, int yy = 1970);
    friend ostream &operator<<(ostream &, const Date &);
    Date &operator++();
    Date operator++(int);
    // operator int() const; // return type cannot be specified
    friend bool operator<(const Date &, const Date &);
    friend bool operator==(const Date &, const Date &);
    friend bool operator!=(const Date &, const Date &);
    bool compare_month(const Date &rhs) const { return mm_ < rhs.mm_; }
};

#endif
