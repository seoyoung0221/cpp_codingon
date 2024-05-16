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

	string getName() {
		return m_name;
	}

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

private:
	string m_shape;
};

int main()
{
	Candy candy1;
	Candy candy2;
	Chocolate chocolate1;
	Chocolate chocolate2;

	Snack* snackBasket[4] = {&candy1, &candy2, &chocolate1, &chocolate2};

	candy1.setPrice(250);
	candy1.setName("ChupaChups");
	candy1.setCompany("A");
	candy1.setFlavor("lemon");

	candy2.setPrice(250);
	candy2.setName("ChupaChups");
	candy2.setCompany("A");
	candy2.setFlavor("strawberry");

	chocolate1.setPrice(1000);
	chocolate1.setName("Ghana");
	chocolate1.setCompany("B");
	chocolate1.setShape("Rectangle");

	chocolate2.setPrice(2000);
	chocolate2.setName("abc");
	chocolate2.setCompany("C");
	chocolate2.setShape("Square");

	for (int i = 0; i < 4; i++)
	{
		cout << snackBasket[i]->getName() << "\n";
	}


	return 0;
}