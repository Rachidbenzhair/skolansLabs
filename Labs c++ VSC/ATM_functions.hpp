#include "ATM.hpp"


using namespace std;

ATM account;
vector<ATM> users;

void Menu()
{
	char userInput;
	string _loginUsername, _loginPassword, _newUsername, _newPassword;
	int _LoginAccountNumber = 0, _newAccountNumber;
	cout << "\t******Welcome to Lund center ATM*******" << endl;
	cout << "Please select an option from menu below " << endl;
	cout << " l-> Login" << endl;
	cout << " c-> Create New Account" << endl;
	cout << " q-> Quit" << endl;
	cin >> userInput;;
	switch (userInput)
	{
	case 'l':
		cout << "Enter Account Number: " << endl;
		while (!(cin >> _LoginAccountNumber))
		{
			cout << "**********************************************************" << endl;
			cout << "ERROR: a number must be entered, enter Account Number agin: " << endl;
			cout << "**********************************************************" << endl;
			cin.clear();
			cin.ignore(132, '\n');
		}
		while (_LoginAccountNumber > 999999 || _LoginAccountNumber < 100000)
		{
			cout << "*******************************************************" << endl;
			cout << "Code doesn't have six digits enter Account Number agin: " << endl;
			cout << "*******************************************************" << endl;
			cin >> _LoginAccountNumber;
		}

		cout << "Enter Username: " << endl;
		cin >> _loginUsername;
		cout << "Enter Password: " << endl;
		cin >> _loginPassword;
		account.AccountLogin(_loginUsername, _loginPassword, _LoginAccountNumber); break;
	case 'c':
	{
		cout << "Enter Account Number: " << endl;
		while (!(cin >> _newAccountNumber))
		{
			cout << "**********************************************************" << endl;
			cout << "ERROR: a number must be entered, enter Account Number agin: " << endl;
			cout << "**********************************************************" << endl;
			cin.clear();
			cin.ignore(132, '\n');
		}
		while (_newAccountNumber > 999999 || _newAccountNumber < 100000)
		{
			cout << "*******************************************************" << endl;
			cout << "Code doesn't have six digits enter Account Number agin: " << endl;
			cout << "*******************************************************" << endl;
			cin >> _newAccountNumber;
		}
		cout << "Enter your user name:" << endl;
		cin >> _newUsername;
		cout << "Enter your passoword: " << endl;
		cin >> _newPassword;
		users.push_back(account);
		account.CreateNewAccount(_newUsername, _newPassword, _newAccountNumber);
		cout << "**************************************************************************" << endl;
		cout << "congratulation you have new account please login with your new credentials" << endl;
		cout << "**************************************************************************" << endl;
		Menu();
		break;
	}
	case 'q':exit(1); break;
	default:
		cout << "\t**************************" << endl;
		cout << "\tInvalid choice test agian" << endl;
		cout << "\t*************************" << endl;
		Menu();
	}
}


void ATM::CreateNewAccount(string newUsername, string newPassword, int newAccountNumber)
{

	time_t tt;
	struct tm* ti;
	time(&tt);
	ti = localtime(&tt);
	std::string str(asctime(ti));
	char trimmed[64]{};
	str.copy(trimmed, strcspn(str.c_str(), "\r\n"));

	int ID = users.size();
	AccountNumber = newAccountNumber;
	username = newUsername;
	password = newPassword;
	beginningBalance = 0;
	accountBalance = 0;
	depositAmount = 0;
	withdrawalAmount = 0;

	fstream recordout;
	recordout.open("Bankdata_record.csv", ios::out | ios::app);
	recordout << AccountNumber << ",";
	recordout << username << ",";
	recordout << password << ",";
	recordout << beginningBalance << ",";
	recordout << accountBalance << ",";
	recordout << depositAmount << ",";
	recordout << withdrawalAmount << ",";
	recordout << trimmed << "\n";
	recordout.close();

}
void ATM::AccountLogin(string loginUsername, string loginPassword, int LoginAccountNumber)
{

	int ID = users.size();
	bool successlogin = false;
	int IDnum, count = 0;
	int setAccountLocation = 0;
	string line, word;

	fstream recordin;
	recordin.open("Bankdata_record.csv", ios::in);

	while (getline(recordin, line, '\n'))
	{
		vector<string> row;
		istringstream sline(line);

		while (getline(sline, word, ','))
		{
			row.push_back(word);
		}

		int IDnum;
		IDnum = stoi(row[0]);

		if (IDnum == LoginAccountNumber)
		{
			count = 1;

			if ((loginUsername == row[1]) && (loginPassword == row[2]))
			{
				successlogin = true;
				setAccountLocation = users.size();
			}
			if (successlogin == true)
			{
				cout << "********************" << endl;
				cout << "Access Granted..." << loginUsername << endl;
				cout << "********************" << endl;

				string str1 = row[3];
				double File_beginningBalance = std::stod(str1);
				string str2 = row[4];
				double File_accountBalance = std::stod(str2);
				string str3 = row[5];
				double File_depositAmount = std::stod(str3);
				string str4 = row[6];
				double File_withdrawalAmount = std::stod(str4);

				cout << " _________________________________________________________________________________________________________________________________\n";
				cout << "|" << left << setw(10) << " User name " << "|" << left << setw(10) << "Account Number" << "|" << left << setw(10) << " beginning Balance" << "|" << left << setw(10) << " Account Balance" << "|" << left << setw(10) << "DepositAmount" << " |" << left << setw(10) << " WithdrawalAmount" << "  |" << left << setw(10) << "    Date of Last Session    " << "   |\n";
				cout << "|___________|______________|__________________|________________|______________|___________________|_______________________________| \n";
				cout << "|" << left << setw(10) << row[1] << " |" << left << setw(10) << row[0] << "    |" << left << setw(15) << left << setw(10) << row[3] << "        |" << left << setw(10) << row[4] << "      |" << left << setw(10) << row[5] << "    |" << left << setw(10) << row[6] << "         |" << left << setw(10) << row[7] << "       |" << endl;
				cout << "|___________|______________|__________________|________________|______________|___________________|_______________________________| \n";


				users.push_back(account);
				users.at(ID).username = row[1];
				users.at(ID).password = row[2];
				users.at(ID).AccountNumber = LoginAccountNumber;
				users.at(ID).beginningBalance = 0;
				users.at(ID).accountBalance = File_accountBalance;
				depositAmount = 0;
				withdrawalAmount = 0;
				users.push_back(account);
				SetAccountLogin(setAccountLocation);
				recordin.close();
				AccountMenu();
			}
			if (successlogin != true)
			{
				cout << "*****************************************************************************" << endl;
				cout << "Access Denied.....Invalid Username/Password/AccountNumber: Test again or create new account" << endl;
				cout << "*****************************************************************************" << endl;
				Menu();
			}
		}
	}
	if (count == 0)
		cout << "Account Number not found\n";
	Menu();
	recordin.close();

}
void ATM::DepositMoney(double depositAmount)//func to deposit any amount of money to the account
{
	users.at(loggedInAccountLocation).accountBalance += depositAmount;
	users.at(loggedInAccountLocation).beginningBalance = users.at(loggedInAccountLocation).accountBalance - depositAmount;
	return;
}
void ATM::WithdrawMoney(double withdrawalAmount)
{
	users.at(loggedInAccountLocation).accountBalance -= withdrawalAmount;
	users.at(loggedInAccountLocation).beginningBalance = users.at(loggedInAccountLocation).accountBalance + withdrawalAmount;
	return;
}
void ATM::SetLastOperation(int accountID, char userInput)
{
	users.at(loggedInAccountLocation).last = userInput;
}
void ATM::SetAccountLogin(int setAccountLocation)
{
	loggedInAccountLocation = setAccountLocation;
}
void ATM::SetBeginningBalance(int accountID)
{
	users.at(accountID).beginningBalance = users.at(loggedInAccountLocation).accountBalance;
}
void ATM::AccountMenu()
{
	char userInput;
	cout << " d-> Deposit Money" << endl;
	cout << " w-> Withdraw Money" << endl;
	cout << " r-> Request Balance" << endl;
	cout << " z-> logout" << endl;
	cout << " q-> Quit" << endl;

	cin >> userInput;
	switch (userInput)
	{
	case 'd':
	{
		cout << "Amount to be Deposited: " << endl;
		cin >> depositAmount;
		DepositMoney(depositAmount);
		SetLastOperation(GetAccountLogin(), userInput);
		AccountMenu();
		break;
	}
	case 'w':
	{
		cout << "Amount of withdrawal: " << endl;
		cin >> withdrawalAmount;
		if (withdrawalAmount > users.at(loggedInAccountLocation).accountBalance)
		{
			cout << "**********************************************************" << endl;
			cout << "you have little money in your account exit or deposit money" << endl;
			cout << "**********************************************************" << endl;
			AccountMenu();
		}
		else
		{
			WithdrawMoney(withdrawalAmount);
			SetLastOperation(GetAccountLogin(), userInput);
			AccountMenu(); break;
		}
	}
	case 'r':
	{
		cout << "******************" << endl;
		cout << "Beginning Balance: " << users.at(loggedInAccountLocation).beginningBalance << endl;
		if ((GetLastOperation(GetAccountLogin()) == 'd') && (depositAmount > 0))
		{
			cout << "Deposit Amount: " << depositAmount << endl;

		}
		if ((GetLastOperation(GetAccountLogin()) == 'w') && (withdrawalAmount > 0))
		{
			cout << "Withdraw Amount: " << withdrawalAmount << endl;

		}
		cout << "Your Balance is: " << users.at(loggedInAccountLocation).accountBalance << endl;
		cout << "******************" << endl;

		time_t tt;
		struct tm* ti;
		time(&tt);
		ti = localtime(&tt);
		std::string str(asctime(ti));
		char trimmed[64]{};
		str.copy(trimmed, strcspn(str.c_str(), "\r\n"));

		cout << " _________________________________________________________________________________________________________________________________\n";
		cout << "|" << left << setw(10) << " User name " << "|" << left << setw(10) << "Account Number" << "|" << left << setw(10) << " beginning Balance" << "|" << left << setw(10) << " Account Balance" << "|" << left << setw(10) << "DepositAmount" << " |" << left << setw(10) << " WithdrawalAmount" << "  |" << left << setw(10) << "    Date of Last Operation    " << " |\n";
		cout << "|___________|______________|__________________|________________|______________|___________________|_______________________________| \n";
		cout << "|" << left << setw(10) << users.at(loggedInAccountLocation).username << " |" << left << setw(10) << users.at(loggedInAccountLocation).AccountNumber << "    |" << left << setw(15) << left << setw(10) << users.at(loggedInAccountLocation).beginningBalance << "        |" << left << setw(10) << users.at(loggedInAccountLocation).accountBalance << "      |" << left << setw(10) << depositAmount << "    |" << left << setw(10) << withdrawalAmount << "         |" << left << setw(10) << trimmed << "       |" << endl;
		cout << "|___________|______________|__________________|________________|______________|___________________|_______________________________| \n";

		uppdat_record();
		AccountMenu();
		break;
	}
	case 'z':uppdat_record(); Menu(); break;
	case 'q':uppdat_record(); exit(1); break;
	default:
		cout << "\t**************************" << endl;
		cout << "\tInvalid choice test agian" << endl;
		cout << "\t*************************" << endl;
		AccountMenu();
	}
}
double ATM::GetAccountBalance(int accountID) const
{
	return users.at(loggedInAccountLocation).accountBalance;
}
double ATM::GetBeginningBalance(int accountID) const
{
	return users.at(accountID).beginningBalance;
}
int ATM::GetAccountLogin() const
{
	return loggedInAccountLocation;
}
char ATM::GetLastOperation(int accountID) const
{
	return users.at(accountID).last;
}
string ATM::GetUsername(int accountID) const
{
	return users.at(GetAccountLogin()).username;
}
void ATM::uppdat_record()
{
	fstream recordin, rcordout;
	recordin.open("Bankdata_record.csv", ios::in);
	rcordout.open("temp_Bankdata_record.csv", ios::out);

	int IDnum, count = 0, i;
	string line, word;

	vector<double>moeny;
	moeny.push_back(users.at(loggedInAccountLocation).beginningBalance);
	moeny.push_back(users.at(loggedInAccountLocation).accountBalance);
	moeny.push_back(depositAmount);
	moeny.push_back(withdrawalAmount);

	while (getline(recordin, line, '\n'))
	{
		vector<string> row;
		istringstream sline(line);

		while (getline(sline, word, ','))
		{
			row.push_back(word);
		}

		IDnum = stoi(row[0]);
		int row_size = row.size();

		if (IDnum == users.at(loggedInAccountLocation).AccountNumber)
		{
			count = 1;
			string temp;
			stringstream convert;
			vector<string> fill;

			copy(moeny.begin(), moeny.end(), ostream_iterator<double>(convert, ","));

			convert << moeny.back();

			while (getline(convert, temp, ','))
			{
				fill.push_back(temp);
			}

			row[3] = fill[0];
			row[4] = fill[1];
			row[5] = fill[2];
			row[6] = fill[3];

			time_t tt;
			struct tm* ti;
			time(&tt);
			ti = localtime(&tt);
			std::string str(asctime(ti));
			char trimmed[64]{};
			str.copy(trimmed, strcspn(str.c_str(), "\r\n"));
			row[7] = trimmed;

			if (!recordin.eof())
			{
				for (i = 0; i < row_size - 1; i++)
				{

					rcordout << row[i] << ",";
				}

				rcordout << row[row_size - 1] << "\n";
			}
		}
		else
		{
			if (!recordin.eof())
			{
				for (i = 0; i < row_size - 1; i++)
				{
					rcordout << row[i] << ",";
				}

				rcordout << row[row_size - 1] << "\n";
			}
		}
		if (recordin.eof())
			break;
	}
	if (count == 0)
		cout << "Record not found\n";

	recordin.close();
	rcordout.close();
	remove("Bankdata_record.csv");
	rename("temp_Bankdata_record.csv", "Bankdata_record.csv");

}







