#pragma once
#include "Person.h"
#include<string>
class Student : public Person
{
	//Inheritance

private:
	int level;
	float GPA;
	string depart;
public:
	void set_level(int l);
	void set_GPA(float p);
	void st_depart(string d);
	int get_level();
	int get_GPA();
	string get_depart();
	void print();
	Student(string n, string g, float a, int l, float p, string d):Person(n,g,a)
	{

		level = l;
		GPA = p;
		depart = d;
	}
};

