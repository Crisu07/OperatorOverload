# OperatorOverload
Operator Overloading practice in C++

## Instructions
Create a C++ class containing the following operations:
- upDate( ) – default constructor. This will set the date to May 11, 1959 (A very important date!!!)
- upDate(int M, int D, int Y) – overloaded constructor. This will set the date to the values passed in through the parameter list represented by Month, Day and Year. If any one of the parameters is out of range, the date is set to the default date.
- upDate( int J) – overloaded constructor – create a date using the Julian date
- ~upDate( ) – destructor. Be sure to de-allocate any memory that was allocated in the constructor.
- void setDate(int M, int D, int Y) – works just like the constructor 
- int getMonth( ) – return the month in integer form
- int getDay( ) – return the day of the month
- int getYear( ) – return the year
- string getMonthName( ) – return the name of the month

Add the necessary class methods (functions) to support the following:
- upDate D1(10,27,2010); 	// overloaded constructor 
- upDate D2(D1); 	// copy constructor
- upDate D3 = D2;	// also copy constructor – initialize D3 to be copy of D2
- D1 = D2;		// assignment operator
- D1 += 5;		// add 5 days to D1, result is stored in D1
- D1 -= 7;			// subtract 7 days from D1, result is stored in D1
- D3 = D2 + 5;  		// add 5 days to D2, assign result to D3
- D3 = 5 + D2; 		// add 5 days to D2, assign result to D3
- D3 = D2 – 4; 		// subtract 4 days from D2, assign result to D3
- int x = D5 – D4; 		// days between D5 and D4. Can be negative or positive
- cout << upDate::GetDateCount(); // a static method that returns the number of upDate objects that currently exist
- cout << D1; 		// will print “10/27/2010”
- D1++;			// increment D1 by one day – postfix style
- ++D1; 			// also increment D1 by one day – prefix style
- D1--; 			// decrement D1 by one day – postfix style
- --D1; 			// decrement D1 by one day – prefix style
- cout << D1.julian();	// print the Julian integer represented by D1
- Comparison Operators
	- if (D1 == D2)
	- if (D1 < D2)
	- if (D1 > D2)

## Running the Program
- Download the zip file and open in an IDE compatible of compiling C++ (I use Visual Studio Community 2022 in this case)
- Run the app and an expected output should display on the console