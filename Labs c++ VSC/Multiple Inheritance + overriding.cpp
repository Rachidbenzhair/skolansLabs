#include<iostream>
#include<string>
using namespace std;

class Employee
{
private:
	string name;
	string job;
	float salary;
public:

	Employee() :name("Unknown"), job("Unknown"), salary(0.0)
	{

	}

	Employee(string n, string j, float s)
	{
		name = n;
		job = j;
		salary = s;
	}

	void set_salary(float s)
	{
		salary = s;
	}

	void set_name(string n)
	{
		name = n;
	}

	void set_job(string j)
	{
		job = j;
	}
	string get_name()
	{
		return name;
	}
	string get_job()
	{
		return job;
	}

	float get_salary()
	{
		return salary;
	}
	void print()
	{
		cout <<"Salary:" << "\t" << salary << endl; 
		cout <<"job:" << "\t" << job << endl;
	}

};
class student
{
private:
	string depertement;
	string research;
	string name;
public:
	student(string d, string r) :depertement(d), research(r)
	{
	}
	void set_depertement(string d)
	{
		depertement = d;
	}
	void set_research(string r)
	{
		research = r;
	}
	void set_name(string n)
	{
		name = n;
	}
	string get_depertement()
	{
		return depertement;
	}
	string get_research()
	{
		return research;
	}
	string get_name()
	{
		return name;
	}
	void print()
	{
		cout <<"Depertamant:" << "\t" << depertement << endl; 
		cout <<"name:" << "\t" << name << endl; 
		cout <<"research:" << "\t" << research << endl;
	}
};
class TeachingAssistant : public student, public Employee
{
public:
	TeachingAssistant(string n, string j, float s, string d, string r) :Employee(n, j, s), student(d, r)
	{

	}
	void print()
	{
		Employee::print();
		student::print();
	}
};
//
//int main()
//{
//	TeachingAssistant s1("Rachid", "Programmer", 60000, "Lund", "teknik");
//	s1.student::set_name("Sami");
//	s1.print();
//
//
//		cout << s1.get_job() << endl;
//		cout << s1.get_depertement() << endl;
//		cout << s1.get_salary() << endl;
//		cout << s1.get_research() << endl;
//}



