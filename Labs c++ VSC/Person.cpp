#include "Person.h"

Person::Person()//Inheritance
{
	name = "unknown";
	gender = "unknown";
	age = 0;
}
Person::Person(string n, string g, float a)
{
	name = n;
	gender = g;
	age = a;
}
void Person::set_age(float a)
{
	age = a;
}
void Person::set_gender(string g)
{
	gender = g;
}
void Person::set_name(string n)
{
	name = n;
}
string Person::get_name()
{
	return name;
}
string Person::get_gender()
{
	return gender;
}
float Person::get_age()
{
	return age;
}
void Person::print()
{

	cout << "Name= " <<  name << "\n" << "Gender= " <<  gender << "\n" << "Age= " << age << endl;
}
