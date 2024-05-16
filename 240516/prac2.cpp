//prac2

#include <iostream>
#include <string>
using namespace std;

class Snack
{
public :
	Snack() {}
	int m_price;
	string m_name;
	string m_company;
};

class Candy : public Snack
{
public :
	Candy() {}
	Candy(int price, string name, string company, string flavor) {
		this->m_price = price;
		this->m_name = name;
		this->m_company = company;
		this->m_flavor = flavor;
	}
private:
	string m_flavor;
};

class Chocolate : public Snack
{
public :
	Chocolate() {}
	Chocolate(int price, string name, string company, string shape) {
		this->m_price = price;
		this->m_name = name;
		this->m_company = company;
		this->m_shape = shape;
	}
private:
	string m_shape;
};

int main()
{
	Candy candy1(250, "ChupaChups", "A", "lemon");
	Candy candy2(250, "ChupaChups", "A", "strawberry");
	Chocolate chocolate1(1000, "Ghana", "B", "square");
	Chocolate chocolate2(2000, "abc", "B", "square");

	Snack snackBasket[4] = {candy1, candy2, chocolate1, chocolate2};


	for (int i = 0; i < 4; i++)
	{
		cout << snackBasket[i].m_name << "\n";
	}


	return 0;
}