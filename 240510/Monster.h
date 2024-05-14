#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Monster
{
public:
	Monster() {
		m_level = 1;
		m_HP = 200;
		m_power = 50;
	}
	void ShowMonsterInfo();

	int getPower();
	int getHP();

	void setloseHP(int attack);
	void setLevel(int level);

private:
	int m_level = 1;
	int m_HP = 200;
	int m_power = 50;

};
