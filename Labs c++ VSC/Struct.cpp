#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

typedef struct
{
	string name;
	int age;
	float gpa;
}info;

#define size 2

int main3()
{
	
	info person[size];

	person[0].name = "Sami";
	person[0].age = 19;
	person[0].gpa = 13.6;

	person[1].name = "rachid";
	person[1].age = 28;
	person[1].gpa = 19.6;



	for (int i = 0; i < size; i++)
	{
		cout << "name : " << person[i].name << endl;
		cout << "age : " << person[i].age << endl;
		cout << "gpa : " << person[i].gpa << endl;
	}



	info student1;
	student1.name = "Sami";
	student1.age = 19;
	student1.gpa = 13.6;

	cout << "name : " << student1.name << endl;
	cout << "age : " << student1.age << endl;
	cout << "gpa : " << student1.gpa << endl;

	info student2;
	student2.name = "rachid";
	student2.age = 28;
	student2.gpa = 19.6;

	cout << "name : " << student2.name << endl;
	cout << "age : " << student2.age << endl;
	cout << "gpa : " << student2.gpa << endl;

	// struct with array

	info student[2];

	student[0].name = "Sami";
	student[0].age = 19;
	student[0].gpa = 13.6;

	student[1].name = "rachid";
	student[1].age = 28;
	student[1].gpa = 19.6;




	for (int i = 0; i < 2; i++)
	{
		cout << "name : " << student[i].name << endl;
		cout << "age : " << student[i].age << endl;
		cout << "gpa : " << student[i].gpa << endl;
	}





	return 0;
}