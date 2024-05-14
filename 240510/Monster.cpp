#include "Monster.h"


int Monster::getHP() { return m_HP; }
int Monster::getPower() { return m_power; }

void Monster::ShowMonsterInfo() {

	cout << "-------몬스터 상태-------\n";
	cout << "레벨 : " << this->m_level << "\n";
	cout << "몬스터의 HP : " << this->m_HP << "\n";
	cout << "------------------------\n";
}

//공격받기 함수
void Monster::setloseHP(int attack) {
	if (m_HP - attack <= 0)
	{
		this->m_HP = 0;
	}
	else {
		this->m_HP -= attack;
	}
}

//몬스터의 레벨 설정 함수
void Monster::setLevel(int level)
{
	this->m_level = level;
	this->m_HP += 10*level;
	this->m_power += 10 * level;
}