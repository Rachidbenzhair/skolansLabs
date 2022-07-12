#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

struct customer
{
	string firstname, lastname;
	string city;
	float grade = 0;
	int id = 0;
};

//int main()
//{
//	customer arr[4];
//
//	arr[0].firstname = "sami";
//	arr[0].lastname = "svensson";
//	arr[0].id = 78052334;
//	arr[0].city = "Malmo";
//	arr[0].grade = 78;
//
//	arr[1].firstname = "Ahmed";
//	arr[1].lastname = "abo";
//	arr[1].id = 77055334;
//	arr[1].city = "Lund";
//	arr[1].grade = 67;
//
//	arr[2].firstname = "Daniel";
//	arr[2].lastname = "lant";
//	arr[2].id = 78081334;
//	arr[2].city = "Malmo";
//	arr[2].grade = 88;
//
//	arr[3].firstname = "Rachid";
//	arr[3].lastname = "jens";
//	arr[3].id = 68053334;
//	arr[3].city = "kalmar";
//	arr[3].grade = 98;
//
//	cout << " ______________________________________________________\n";
//	cout << "|" << left << setw(10) << " Firstname" << "|" << left << setw(10) << " Lastname" << "|" << left << setw(10) << "    ID" << "|" << left << setw(10) << "  City" << "|" << left << setw(10) << "  Grade" << "|" << endl;
//	cout << "|__________|__________|__________|__________|__________|  \n";
//
//	for (int i = 0; i <= 3; i++)
//	{
//		cout << "|" << left << setw(10) << arr[i].firstname << "|" << left << setw(10) << arr[i].lastname << "|" << left << setw(10) << arr[i].id << "|" << left << setw(10) << arr[i].city << "|" << left << setw(10) << arr[i].grade << "|" << endl;
//		cout << "|__________|__________|__________|__________|__________|  \n";
//	}
//
//
//
//}

