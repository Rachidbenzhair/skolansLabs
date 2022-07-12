#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

char mainMenu();
void logIn();
void createUser();
//int main() {
//
//	char mainMenuChoice;
//
//	cout << "Welcome to the Bank! Please select one of the following options:\n\n";
//
//
//
//retry:
//
//
//
//	mainMenuChoice = mainMenu();
//
//	if (mainMenuChoice == 'l' || mainMenuChoice == 'L') {
//
//		cout << "You have chosen login!\n\n";
//
//		logIn();
//
//	}
//
//	else if (mainMenuChoice == 'c' || mainMenuChoice == 'C') {
//
//		cout << "You have chosen to create a new account!\n\n";
//		createUser();
//
//	}
//
//	else if (mainMenuChoice == 'q' || mainMenuChoice == 'Q') {
//
//		cout << "Exiting...\n";
//
//		exit(EXIT_FAILURE);
//
//	}
//
//	else {
//
//		cout << "Invalid Option\n";
//
//		goto retry;
//
//	}
//
//	return 0;
//
//}
void createUser() 
{

	string username, password;

	string user, pass;

	bool userValid = false;



	ifstream accountInformationIn;

	ofstream accountInformationOut;



retry:



	cout << "Welcome to the create a user screen.\n\n";

	cout << "==================================\n";

	cout << "Please enter your desired username:\n";

	cin >> username;

	cout << "Please enter your password:\n";

	cin >> password;



	accountInformationIn.open("UserData.txt");



	while (!userValid) {

		accountInformationIn >> user >> pass;

		if (username != user && password != pass) {

			cout << "Account created successfully!\n";

			cout << "Welcome " << username << endl;

			userValid = true;
			mainMenu();

		}

		else if (username == user && password == pass) {

			cout << "Username already in user.\n";
			createUser();

			

		}

		else {

			cout << "Unknown Error... Restarting\n";
			mainMenu();

			

		}

	}



	accountInformationIn.close();



	accountInformationOut.open("UserData.txt", ios::out | ios::in | ios::app);

	user = username;

	pass = password;

	cout << "Saving your information.\n";

	if (userValid) {

		accountInformationOut << user << " " << pass << endl;

	}

	accountInformationOut.close();

}


void logIn() {

	string username, password;

	string user, pass;



	ifstream accountInformationIn;

	ofstream accountInformationOut;



	cout << "Please enter username\n";

	cin >> username;

	cout << "Please enter a password\n";

	cin >> password;



	accountInformationIn.open("UserData.txt");



	if (accountInformationIn.is_open()) {


		while (!accountInformationIn.eof()) {

			accountInformationIn >> user >> pass;

			if (username == user && password == pass) {

				cout << "Username and passwords match!\n";
				mainMenu();

			}

		}

	}

	else {

		cout << "File not open\n";

	}

	accountInformationIn.close();

}

char mainMenu() {

	char menuOption;

	cout << "================================================================\n\n";

	cout << "( L ) -> Login\n";

	cout << "( C ) -> Create Account\n";

	cout << "( Q ) -> Quit\n\n";

	cout << "================================================================\n\n";

	cin >> menuOption;

	return menuOption;

}
