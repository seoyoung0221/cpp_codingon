#include <iostream>

class Monster
{
public: 
	std::string m_Name;
	int m_HP;
private:
	int m_MP;
protected:
	int m_DEF;
public :
	int GETHP() 
	{
		return m_HP;
	}

	int GETMP()
	{
		return m_MP;
	}
	virtual void Func()
	{

	}
};

class Fighter : public Monster
{
public:
	void Func() override
	{
		m_HP;
		m_MP;
		m_DEF;
	}
};

class Archer : private Monster
{
public:
	void Func() override
	{
		m_HP;
		m_MP;
		m_DEF;
	}
};

class Wizard : protected Monster
{
public:
	void Func() override
	{
		m_HP;
		m_MP;
		m_DEF;
	}
};

class Base {

};

/*
int main()
{
	Monster Temp_Monster;
	Fighter Temp_Fighter;
	Archer Temp_Archer;
	Wizard Temp_Wizard;

	Temp_Monster.m_HP;
	Temp_Monster.m_MP;
	Temp_Monster.m_DEF;

	Temp_Fighter.m_HP;
	Temp_Fighter.m_MP;
	Temp_Fighter.m_DEF;

	Temp_Archer.m_HP;
	Temp_Archer.m_MP;
	Temp_Archer.m_DEF;

	Temp_Wizard.m_HP;
	Temp_Wizard.m_MP;
	Temp_Wizard.m_DEF;



}
*/