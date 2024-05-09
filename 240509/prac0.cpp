#include <iostream>
#include <string>

using namespace std;

// 기능 모음
class Function 
{
	void openAccount() {}
	bool checkAccount() {}
	void transferAccount() {}
	bool checkCustomerInfo() {}
	void manageCustomer() {}
	void manageBank() {}
	bool checkCustomerInfo() {}
	bool checkBankInfo() {}

};

//고객의 정보와 고객이 쓸 수 있는 기능
class CustomerInfo
{
	string customerID;
	string name;
	string account;
	string phoneNumber;

	void openAccount() {}
	bool checkAccount() {}
	void transferAccount() {}
	bool checkCustomerInfo() {}
};

//은행의 정보와 은행이 쓸 수 있는 기능
class BankInfo{
	string customerID;
	string BankID;
	string BankAddress;

	string name;
	string account;
	string phoneNumber;

	bool checkAccount() {}
	void manageCustomer() {}
	void manageBank() {}
	bool checkCustomerInfo() {}
	bool checkBankInfo() {}
};


int main() {


}