#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Character
{
public:
	Character(string name) 
	{
		this->m_name = name;
	}

	Character(string name, int level, int itemNum, int HP, int EXP) 
	{
		this->m_name = name;
		this->m_level = level;
		this->m_item_num = itemNum;
		this->m_HP = HP;
		this->m_EXP = EXP;
	}

	string getName();
	int getLevel();
	int getItemNum();
	int getPower();
	int getEXP();
	int getHP();

	void ShowCharacterInfo();
	void setChangeName(string name);
	void setLevelUp();
	void setPickUpItem();
	void setUseItem();
	void setloseHP(int attack);
	void setRestoreHP();
	void setEXP(int monsterLevel);
	
private:

	string m_name;
	int m_level = 1;
	int m_item_num = 0;
	int m_HP = 100;
	int m_max_HP = 100;
	int m_EXP = 0;
	int m_max_EXP = 100;
	int m_power = 50;
	
};