//240520
//prac3 static ���

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Snack
{
public:
	static int snackNum;

	Snack() {}
	/*
	void setPrice(int price) {
		this->m_price = price;
	}

	void setName(string name) {
		this->m_name = name;
	}

	void setCompany(string company) {
		this->m_company = company;
	}
	string getCompany() {
		return m_company;
	}

	string getName() {
		return m_name;
	}
	*/
	

	static int getSnackNum() {
		return snackNum;
		//return 0;
	}

	void setAddSnackNum() {
		//Snack::snackNum++;
	}

private:
	int m_price = 0;
	string m_name;
	string m_company;
};

int Snack::snackNum = 0;


class Candy : public Snack
{
public:
	Candy() {}

	void setFlavor(string flavor) {
		this->m_flavor = flavor;
	}
	/*
	void printCompany() {
		cout << getName() << "�� ������� " << getCompany() << "�Դϴ�. \n";
	}
	*/
private:
	string m_flavor;
};

class Chocolate : public Snack
{
public:
	Chocolate() {}

	void setShape(string shape) {
		this->m_shape = shape;
	}
	/*
	void printCompany() {
		cout << getName() << "�� ������� " << getCompany() << "�Դϴ�. \n";
	}
	*/
private:
	string m_shape;
};


int main() {
	Snack* snackbasket;
	vector<string> snack;
	int option = -1;

	while (option != 0)
	{
		cout << "���� �ٱ��Ͽ� �߰��� ������ ���ÿ�. (1. ����, 2. ���ݸ�, 0. ����)\n";
		cin >> option;
		switch (option)
		{
		case 0:
		{
			cout << "���� �ٱ��Ͽ� ��� ������ ������ " << snackbasket->getSnackNum() << "�� �Դϴ�.\n";
			break;
		}
		case 1:
		{
			snackbasket->setAddSnackNum();
			/*string flavor;
			cout << "���� �Է��ϼ��� : ";
			cin >> flavor;*/

			break;
		}
		case 2:
		{
			snackbasket->setAddSnackNum();
			/*string shape;
			cout << "����� �Է��ϼ��� : ";
			cin >> shape;*/
			break;
		}
		}



	}



	return 0;
}