#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Studant
{
private:
	string name;
	int age;
public:
	Studant(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void print()
	{
		cout << name << " " << age << endl;
	}


};


void vector_enkl()
{

	vector<string>names;

	names.push_back("sami");
	names.push_back("Rachid");
	names.push_back("Lisa");


	names.insert(names.begin() + 1, "Ahmed");


	/*names.pop_back();*/
	/*cout << names.at(2) << endl;*/
	//cout << names.size();

	for (string name : names)
		cout << name << endl;
}


//int main_9()
//{
//
//	vector<Studant> stud;
//	stud.push_back(Studant("Sami", 32));
//	stud.push_back(Studant("Lisa", 22));
//	stud.push_back(Studant("Rachid", 42));
//
//	for (Studant item : stud)
//		item.print();
//
//	return 0;
//}

