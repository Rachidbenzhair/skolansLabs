#include<iostream>
#include<string>
using namespace std;
class person
{
private:

	string name;
	string gender;
	float age;
public:

	person(string n, string g, float a)
	{
		name = n;
		gender = g;
		age = a;
	}
	//void set_age(float a)
	//{
	//	age = a;
	//}
	//void set_gender(string g)
	//{
	//	gender = g;
	//}
	//void set_name(string n)
	//{
	//	name = n;
	//}
	//string get_name()
	//{
	//	return name;
	//}
	//string get_gender()
	//{
	//	return gender;
	//}
	//float get_age()
	//{
	//	return age;
	//}

	friend void print(person p);
	

};

void print(person p)
{
	cout << "Name= " << p.name << "\n" << "Gender= " << p.gender << "\n" << "Age= " << p.age << endl;

}

//void main()
//{
//	person x("Rachid", "Man", 35);
//	print(x);
//}
