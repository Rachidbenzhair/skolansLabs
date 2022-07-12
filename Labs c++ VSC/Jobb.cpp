#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
//
//int main()
//{
//	string username;
//	string password;
//	string user;
//	string pass;
//	int option = 0;
//
//	cout << "choose option below" << endl;
//	cout << "1: signup" << endl;
//	cout << "2: login" << endl;
//	cout << "3: exit" << endl;
//	cin >> option;
//
//	if (option == 1)
//	{
//		fstream infile;
//		infile.open("users.txt", ios::app);
//		cout << "Add a username then password.\n";
//		cout << "Enter username: ";
//		cin >> username;
//		cout << "Enter password: ";
//		cin >> password;
//		if (!infile.is_open())
//		{
//			infile.open("users.txt");
//		}
//		infile << username << " " << password << endl;;
//		infile.close();
//		
//		cout << "Register Success." << endl;
//		main();
//	}
//	else if (option == 2)
//	{
//		ifstream infile;
//		cout << "Enter UserName: ";
//		cin >> user;
//		cout << "Enter Password: ";
//		cin >> pass;
//		infile.open("users.txt");
//
//		if (infile.is_open())
//		{
//			while (!infile.eof())
//			{
//				infile >> username >> password;
//
//				if (user == username && pass == password)
//				{
//					cout << "Login successfully." << endl;
//					main();
//
//				}
//
//			}
//			cout << "Wrong username or password!" << endl;
//			main();
//		}
//		
//	}
//	else if (option == 3)
//	{
//		exit;
//	}
//	return 0;
//}
