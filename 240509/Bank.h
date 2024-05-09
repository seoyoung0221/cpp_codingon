#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bank {
private:
	string customerID;
	string BankID;
	string BankAddress;

	string name;
	string account;
	string phoneNumber;

public:

	bool checkAccount() {}
	void manageCustomer() {}
	void manageBank() {}
	bool checkCustomerInfo() {}
	bool checkBankInfo() {}
};