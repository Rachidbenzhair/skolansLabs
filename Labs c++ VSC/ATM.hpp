#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include<fstream>
#include<list>
#include <map>
#include <ctime>
#include <sstream>
#include <iterator>
#include <cstring>


using namespace std;

class ATM
{
private:
	int loggedInAccountLocation;
	double accountBalance;
	double beginningBalance;
	double depositAmount;
	double withdrawalAmount;
	string username;
	string password;
	int AccountNumber;
	string loginUsername;
	string loginPassword;
	int LoginAccountNumber;
	int last;

public:

	void CreateNewAccount(string newUsername, string newPassword, int newAccountNumber);//creates the user account
	void AccountLogin(string loginUsername, string loginPassword, int LoginAccountNumber);//used to login the user using account det
	void DepositMoney(double depositAmount);//func to deposit any amount of money to the account
	void WithdrawMoney(double withdrawalAmount);//func to withdraw any amount of money from the account
	void SetAccountLogin(int setAccountLocation);//sets the location for the account information in the vector
	void SetBeginningBalance(int accountID);//Func that ensures the users account starts as 0 as well as that it updates when perfor
	void SetLastOperation(int accountID, char userInput);//defines last action made by user
	void AccountMenu();//representing the menu of user choices
	int GetAccountLogin() const;//makes sure the account login is in the list
	double GetAccountBalance(int accountID) const;//shows the users account balance
	double GetBeginningBalance(int accountID) const;//retrieves the balance before last performed action
	char GetLastOperation(int accountID) const;//gets the last action, ex withdrawal or deposit
	string GetUsername(int accountID) const;//gets the username of the logged in account
	void uppdat_record();
};