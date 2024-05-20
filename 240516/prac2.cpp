//prac2

#include <iostream>
#include <string>
using namespace std;

class Snack
{
public :
	Snack() {}

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

private:
	int m_price;
	string m_name;
	string m_company;
};

class Candy : public Snack
{
public :
	Candy() {}

	void setFlavor(string flavor) {
		this->m_flavor = flavor;
	}

	void printCompany() {
		cout << getName() << "의 제조사는 " << getCompany() << "입니다. \n";
	}

private:
	string m_flavor;
};

class Chocolate : public Snack
{
public :
	Chocolate() {}

	void setShape(string shape) {
		this->m_shape = shape;
	}

	void printCompany() {
		cout << getName() << "의 제조사는 " << getCompany() << "입니다. \n";
	}
private:
	string m_shape;
};

int main()
{
	Candy candy1;
	Candy candy2;
	Chocolate chocolate1;
	Chocolate chocolate2;
	string company[4];

	Snack* snackBasket[4] = {&candy1, &candy2, &chocolate1, &chocolate2};

	candy1.setPrice(250);
	candy1.setName("ChupaChups");
	candy1.setFlavor("lemon");

	candy2.setPrice(250);
	candy2.setName("ChupaChups");
	candy2.setFlavor("strawberry");

	chocolate1.setPrice(1000);
	chocolate1.setName("Ghana");
	chocolate1.setShape("Rectangle");

	chocolate2.setPrice(2000);
	chocolate2.setName("abc");
	chocolate2.setShape("Square");

	for (int i = 0; i < 4; i++)
	{
		cout << snackBasket[i]->getName() << "\n";
	}

	for (int i = 0; i < 4; i++)
	{
		cout << snackBasket[i]->getName() << "의 제조 회사를 입력하세요. " << "\n";
		cin >> company[i];
		snackBasket[i]->setCompany(company[i]);
	}

	Candy* can1 = (Candy*)snackBasket[0];
	Candy* can2 = (Candy*)snackBasket[1];
	Chocolate* cho1 = (Chocolate*)snackBasket[2];
	Chocolate * cho2 = (Chocolate*)snackBasket[3];

	can1->printCompany();
	can2->printCompany();
	cho1->printCompany();
	cho2->printCompany();

	return 0;
}