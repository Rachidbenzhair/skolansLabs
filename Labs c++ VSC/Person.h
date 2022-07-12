#pragma once
#include<iostream>
#include<string>
using namespace std;
class Person		//Inheritance
{
private:
	string name;
	string gender;
	float age;
public:
	Person();
	Person(string n, string g, float a);
	void set_age(float a);
	void set_gender(string g);
	void set_name(string n);
	string get_name();
	string get_gender();
	float get_age();
	virtual void print();


};

