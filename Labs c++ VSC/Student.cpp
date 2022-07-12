#include "Student.h"
#include<string>

void Student::set_level(int l)
{
	level = l;
}

void Student::set_GPA(float p)
{
	GPA = p;
}

void Student::st_depart(string d)
{

	depart = d;
}

int Student::get_level()
{
	return level;
}

int Student::get_GPA()
{
	return GPA;
}

string Student::get_depart()
{
	return depart;
}

void Student::print()
{

	Person::print();
	cout <<"Level= "<< level << "\n" <<"GPA= "<< GPA << "\n"  <<"Depart= "<< depart << endl;


}
