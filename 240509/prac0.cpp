#include <iostream>
#include <string>

using namespace std;

// ��� ����
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

//���� ������ ���� �� �� �ִ� ���
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

//������ ������ ������ �� �� �ִ� ���
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