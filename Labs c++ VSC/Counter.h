#pragma once
class Counter
{
private:
	 int count;					//count
public:
	Counter(): count(0)			// constructor
	{}
	Counter (int c):count(c)	//counstructor
	{}
	int get_count();			//return count
	Counter operator ++();		//prefix operator
	Counter operator --();		//prefix operator
	Counter operator ++(int);	//postfix operator
	Counter operator --(int);	//postfix operator


};

