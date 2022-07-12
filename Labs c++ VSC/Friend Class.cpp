#include<iostream>
#include<string>
using namespace std;
class PPerson
{
private:
	string name;
	string gender;
	float age;
public:

	PPerson(string n, string g, float a)
	{
		name = n;
		gender = g;
		age = a;
	}
	void set_age(float a)
	{
		age = a;
	}
	void set_gender(string g)
	{
		gender = g;
	}
	void set_name(string n)
	{
		name = n;
	}
	string get_name()
	{
		return name;
	}
	string get_gender()
	{
		return gender;
	}
	float get_age()
	{
		return age;
	}

	friend class printclass;
};

class printclass
{
public:
	void print(PPerson p)
	{
		cout << "Name= " << p.name << "\n" << "Gender= " << p.gender << "\n" << "Age= " << p.age << endl;
	}
};

//void main()
//{
//	PPerson x("Rachid", "Man", 35);
//	printclass B;
//	B.print(x);
//}
