#include <iostream>								
#include <string>
#include<vector>
using namespace std;

class ATM
{
private:
	double accountBalance = 0;
	double beginningBalance = 0;
	double depositAmount = 0;
	double withdrawalAmount = 0;
	string username = "sami";
	string password = "1234";
	string loginUsername;
	string loginPassword;
	int last = 0;

public:

	void CreateNewAccount()	//creates the user account
	{
		cout << "Enter your user name:" << endl;
		cin >> username;
		cout << "Enter your passoword: " << endl;
		cin >> password;
		cout << "**************************************************************************" << endl;
		cout << "congratulation you have new account please login with your new credentials" << endl;
		cout << "**************************************************************************" << endl;
		GetAccountLogin();
	}
	void AccountLogin()	//used to login the user using account details
	{

		cout << "Enter Username: " << endl;
		cin >> loginUsername;
		cout << "Enter Password: " << endl;
		cin >> loginPassword;

		if ((loginUsername == username) && (loginPassword == password))
		{
			cout << "********************" << endl;
			cout << "Access Granted..." << loginUsername << endl;
			cout << "********************" << endl;
			GetAccountMenu();
		}
		else
		{
			cout << "*****************************************************************************" << endl;
			cout << "Access Denied.....Invalid Username/Password: Test again or create new account" << endl;
			cout << "*****************************************************************************" << endl;
			GetAccountLogin();
		}
	}
	void DepositMoney()//func to deposit any amount of money to the account
	{
		cout << "Amount to be Deposited: " << endl;
		cin >> depositAmount;
		accountBalance += depositAmount;
		beginningBalance = accountBalance - depositAmount;
		last = 1;
		GetAccountMenu();
	}
	void WithdrawMoney()//func to withdraw any amount of money from the account
	{
		cout << "Amount of withdrawal: " << endl;
		cin >> withdrawalAmount;
		if (withdrawalAmount > accountBalance)
		{
			cout << "**********************************************************" << endl;
			cout << "you have little money in your account exit or deposit money" << endl;
			cout << "**********************************************************" << endl;
			GetAccountMenu();
		}
		else
		{
			accountBalance -= withdrawalAmount;
			beginningBalance = accountBalance + withdrawalAmount;
			last = 2;
			GetAccountMenu();
		}

	}
	int GetAccountLogin()//makes sure the account login is in the list
	{
		char userInput;
		cout << "\t******Welcome to Lund center ATM*******" << endl;
		cout << "Please select an option from menu below " << endl;
		cout << " l-> Login" << endl;
		cout << " c-> Create New Account" << endl;
		cout << " q-> Quit" << endl;
		cin >> userInput;;
		switch (userInput)
		{
		case 'l':AccountLogin(); break;
		case 'c':CreateNewAccount(); break;
		case 'q':exit(1); break;
		default:
			cout << "\t**************************" << endl;
			cout << "\tInvalid choice test agian" << endl;
			cout << "\t*************************" << endl;
			GetAccountLogin();
		}
		return 0;

	}
	double GetAccountBalance()//shows the users account balance
	{
		cout << "********************" << endl;
		cout << "Beginning Balance: " << beginningBalance << endl;
		if (last == 1)
		{
			cout << "Deposit Amount: " << depositAmount << endl;
		}
		if (last == 2)
		{
			cout << "Withdraw Amount: " << withdrawalAmount << endl;
		}
		cout << "Your Balance is: " << accountBalance << endl;
		cout << "********************" << endl;
		GetAccountMenu();
		return 0;
	}
	char GetAccountMenu()//representing the menu of user choices
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
		case 'd':DepositMoney(); break;
		case 'w':WithdrawMoney(); break;
		case 'r':GetAccountBalance(); break;
		case 'z':GetAccountLogin(); break;
		case 'q':exit(1); break;
		default:
			cout << "\t**************************" << endl;
			cout << "\tInvalid choice test agian" << endl;
			cout << "\t*************************" << endl;
			GetAccountLogin();
		}
	}

};

//int main()
//{
//	
//	ATM user;
//	user.GetAccountLogin();
//
//
//}






