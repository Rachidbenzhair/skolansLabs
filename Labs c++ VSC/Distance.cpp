#include "Distance.h"
#include<iostream>

using namespace std;

Distance::Distance():feet(0), inches(0.0)
{
}
Distance::Distance(int f, float i):feet(f), inches(i)
{
}
void Distance::setDistance(int f, float i)
{
	feet = f;
	inches = i;

}
void Distance::print()
{
	cout << "feet: " << "\t" << feet << "\t" << "inches: " << inches << endl;
	

}
Distance::~Distance()
{
}
Distance Distance::add_distance(Distance pass)//Passing Objects as Arguments
{
	Distance result;
	result.feet= feet + pass.feet;
	result.inches=inches + pass.inches;
	return result;
}
Distance Distance::operator+(Distance d2)
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	return Distance(f, i);
}
Distance Distance::operator -(Distance d2)
{
	int f = feet - d2.feet;
	float i = inches - d2.inches;
	return Distance(f, i);
}
