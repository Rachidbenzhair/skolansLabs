#include <string>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class User
{
private:
	string username, password;
public:
	void setUsername(string u);
	void setPassword(string p);
	string getUsername();
	string getPassword();

};

void User::setUsername(string u)
{
	username = u;
}
void User::setPassword(string p)
{
	password = p;
}
string User::getUsername()
{
	return username;
}
string User::getPassword()
{
	return password;
}

User users[100];

int main6()
{
	
	int size = 0;
	string username, password;

	fstream fileout("userfile.txt", ios::app);

	while (true)
	{
		cout << "enter username: " << endl;
		cin >> username;
		cout << "enter password: " << endl;
		cin >> password;

		User Newuser;
		Newuser.setUsername(username);
		Newuser.setPassword(password);
		users[size++] = Newuser;
		fileout << Newuser.getUsername() << "," << Newuser.getPassword() << endl;

		for (int i = 0; i < size; i++)
		{
			cout  << "Username: " << users[i].getUsername() << "\t" << "Password: " << users[i].getPassword() << endl;
		}
	}

}
