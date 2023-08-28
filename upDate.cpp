// upDate.cpp
#include "upDate.h"
#include <iostream>
#include <string>
using namespace std;

int upDate::count = 0; // counter
// pass in month day year, convert then reutrn Julian number
int Greg2Julian(int month, int day, int year)
{
	int I = year;
	int J = month;
	int K = day;
	int JD;

	JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 *
		(J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
	return JD;
}

// pass in Julian date and return correct month day year (starts from jan 1 4713bc/-4712)
void Julian2Greg(int JD, int& month, int& day, int& year)
{
	int I;
	int J;
	int K;
	int L = JD + 68569;
	int N = 4 * L / 146097;

	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	// reassign values for references
	year = I;
	month = J;
	day = K;
}

// Checking for leap years
bool leapcheck(int Y)
{
	if (Y % 4 == 0) // if the year is divisable by 4
	{
		if (Y % 100 == 0) // if it is divisable by 100
		{
			if (Y % 400 == 0) // if divisable by 400 then its a leap year
			{
				return true;
			}
			else // not a leap year
			{
				return false;
			}
		}
		else // if not divisable by 100 but by 4 then its a leap year
		{
			return true;
		}
	}
	else // not a leap year
	{
		return false;
	}
}

// default constructor
upDate::upDate()
{
	date = new int[3];
	date[0] = 5; // month
	date[1] = 11; // day
	date[2] = 1959; // year
	count++;
}

// overloaded constructor
upDate::upDate(int M, int D, int Y)
{
	date = new int[3];
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // max num of days for each month

	if (Y > -4712) // Check for valid Years (4713 BC = -4712)
	{
		if ((M >= 1) and (M <= 12)) // Check for valid month range
		{
			if (M != 2) // Valid dates for every month besides Feb
			{
				int temp = days[M - 1];
				if ((D > 0) and (D <= temp)) // Check for valid days range depending on the month
				{
					date[0] = M;
					date[1] = D;
					date[2] = Y;
				}
				else
				{
					date[0] = 5;
					date[1] = 11;
					date[2] = 1959;
				}
			}
			else // if the month IS Feb
			{
				int temp = days[M - 1];
				if ((D > 0) and (D <= temp))
				{
					date[0] = M;
					date[1] = D;
					date[2] = Y;
				}
				else if (D == 29) // if the day is 29, make sure the year is a leap year
				{
					bool check = leapcheck(Y);
					if (check) // if it is a leap year then valid date
					{
						date[0] = M;
						date[1] = D;
						date[2] = Y;
					}
					else // if the day is 29 and it is not a leap year, invalid
					{
						date[0] = 5;
						date[1] = 11;
						date[2] = 1959;
					}
				}
				else
				{
					date[0] = 5;
					date[1] = 11;
					date[2] = 1959;
				}
			}
		}
		else
		{
			date[0] = 5;
			date[1] = 11;
			date[2] = 1959;
		}
	}
	else // set to default date
	{
		date[0] = 5;
		date[1] = 11;
		date[2] = 1959;
	}
	count++;
}

// overload constructor for creating a date given julian
upDate::upDate(int J)
{
	//date = new int[3];
	Julian2Greg(J, date[0], date[1], date[2]);
	count++;
}

// destructor
upDate::~upDate() // destructor is automatically called upon
{
	// cout << "deleting" << endl; // testing destructor
	delete[] date;
	count--;
}

// should work just like the constructor
void upDate::setDate(int M, int D, int Y)
{
	date = new int[3];
	date[0] = M;
	date[1] = D;
	date[2] = Y;
}

int upDate::getMonth()
{
	return date[0];
}

int upDate::getDay()
{
	return date[1];
}

int upDate::getYear()
{
	return date[2];
}

int upDate::julian()
{
	int j = Greg2Julian(date[0], date[1], date[2]);
	return j;
}

int upDate::GetDateCount()
{
	return count;
}

string upDate::getMonthName()
{
	string mon[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return mon[date[0] - 1]; //  return corresponding index for month
}

ostream& operator<<(ostream& output, const upDate& d)
{
	output << d.date[0] << "/" << d.date[1] << "/" << d.date[2];
	return output;
}

// copy constructor
upDate::upDate(const upDate& other)
{
	date = new int[3];
	date[0] = other.date[0];
	date[1] = other.date[1];
	date[2] = other.date[2];
	*date = *(other.date);
	count++;
}

// assignment operator
upDate upDate::operator=(const upDate& other) // similar to copy constructor
{
	date[0] = other.date[0];
	date[1] = other.date[1];
	date[2] = other.date[2];
	*date = *(other.date);
	return *this; // return updated date
}

// += operator (D1 += 5; add 5 days to D1, result is stored in D1)
upDate upDate::operator+=(int n)
{
	int j = julian(); // convert to julian
	j = j + n; // increment by n
	Julian2Greg(j, date[0], date[1], date[2]); // convert back
	return *this;
}

// -= operator (D1 -= 7; subtract 7 days from D1, result is stored in D1)
upDate upDate::operator-=(int n)
{
	int j = julian();
	j = j - n;
	Julian2Greg(j, date[0], date[1], date[2]);
	return *this;
}

// + operator (D3 = D2 + 5; add 5 days to D2, assign result to D3)
upDate upDate::operator+(int n)
{
	// similar to += function
	int j = julian();
	j = j + n;
	upDate inc(date[0], date[1], date[2]); // (error before: d5 gets overwritten if editing date directly fix: set inc as a new date)
	Julian2Greg(j, inc.date[0], inc.date[1], inc.date[2]);
	return inc;
}

// + operator 2 (D3 = 5 + D2; add 5 days to D2, assign result to D3)
upDate operator+(int n, const upDate& d)
{
	int j = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	j = j + n;
	upDate inc(d.date[0], d.date[1], d.date[2]); // create new date to avoid overwriting existing one
	Julian2Greg(j, inc.date[0], inc.date[1], inc.date[2]);
	return inc;
}

// - operator (D3 = D2 – 4; subtract 4 days from D2, assign result to D3)
upDate upDate::operator-(int n)
{
	int j = julian();
	j = j - n;
	upDate dec(date[0], date[1], date[2]);
	Julian2Greg(j, dec.date[0], dec.date[1], dec.date[2]);
	return dec;
}

// - operator 2 (int x = D5 – D4; days between D5 and D4. Can be negative or positive)
int operator-(const upDate& c, const upDate& d)
{
	int startD = Greg2Julian(c.date[0], c.date[1], c.date[2]);
	int endD = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	int daysbw = startD - endD;
	return daysbw;
}

// ++ postfix (d1++, increment date by one day)
void operator++(upDate& d, int dummy) // adding a dummy allows it to differentiate between the post and pre fix
{
	/* This should also work for incrementing (taken from lecture)
	*(this->date)++;
	return *this;
	*/
	int j = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	j = j + 1;
	Julian2Greg(j, d.date[0], d.date[1], d.date[2]);
}

// ++ prefix (++d1, increment date by one day) (void does not work for prefix so just return a date instead)
upDate operator++(upDate& d)
{
	int j = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	j = j + 1;
	upDate inc(d.date[0], d.date[1], d.date[2]);
	Julian2Greg(j, inc.date[0], inc.date[1], inc.date[2]);
	return inc;
}

// -- postfix (d1--, increment one day back)
void operator--(upDate& d, int dummy)
{
	int j = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	j = j - 1;
	Julian2Greg(j, d.date[0], d.date[1], d.date[2]);
}

//  -- prefix (--d1, increment one day back)
upDate operator--(upDate& d)
{
	int j = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	j = j - 1;
	upDate inc(d.date[0], d.date[1], d.date[2]);
	Julian2Greg(j, inc.date[0], inc.date[1], inc.date[2]);
	return inc;
}

// == comparison
bool upDate::operator==(const upDate & d)
{
	int d1 = Greg2Julian(date[0], date[1], date[2]);
	int d2 = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	if (d1 == d2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// < comparison
bool upDate::operator<(const upDate& d)
{
	int d1 = Greg2Julian(date[0], date[1], date[2]);
	int d2 = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	if (d1 < d2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// > comparison
bool upDate::operator>(const upDate& d)
{
	int d1 = Greg2Julian(date[0], date[1], date[2]);
	int d2 = Greg2Julian(d.date[0], d.date[1], d.date[2]);
	if (d1 > d2)
	{
		return true;
	}
	else
	{
		return false;
	}
}