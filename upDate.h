// upDate.h
#ifndef UPDATE_H
#define UPDATE_H
#include <iostream>
#include <string>
using namespace std; // to refer to string

class upDate
{
private:
	int* date;
	static int count;
public:
	upDate(); // default constructor
	upDate(int M, int D, int Y); // overloaded contructor
	upDate(int J); // overload constructor
	~upDate(); // destructor
	void setDate(int M, int D, int Y);
	int getMonth();
	int getDay();
	int getYear();
	int julian();
	static int GetDateCount();
	string getMonthName();
	friend ostream& operator<<(ostream& output, const upDate& d);
	upDate(const upDate& other); // copy constructor
	upDate operator=(const upDate& other); // assignment operator
	upDate operator+=(int n);
	upDate operator-=(int n);
	upDate operator+(int n);
	friend upDate operator+(int n, const upDate& d);
	upDate operator-(int n);
	friend int operator-(const upDate& c, const upDate& d);
	friend void operator++(upDate& d, int dummy); // postfix
	friend upDate operator++(upDate& d); // prefix
	friend void operator--(upDate& d, int dummy); // postfix
	friend upDate operator--(upDate& d); // prefix
	// comparison operators
	bool operator==(const upDate& d);
	bool operator<(const upDate& d);
	bool operator>(const upDate& d);
};

#endif