#include "Monster.h"


int Monster::getHP() { return m_HP; }
int Monster::getPower() { return m_power; }

void Monster::ShowMonsterInfo() {

	cout << "-------���� ����-------\n";
	cout << "���� : " << this->m_level << "\n";
	cout << "������ HP : " << this->m_HP << "\n";
	cout << "------------------------\n";
}

//���ݹޱ� �Լ�
void Monster::setloseHP(int attack) {
	if (m_HP - attack <= 0)
	{
		this->m_HP = 0;
	}
	else {
		this->m_HP -= attack;
	}
}

//������ ���� ���� �Լ�
void Monster::setLevel(int level)
{
	this->m_level = level;
	this->m_HP += 10*level;
	this->m_power += 10 * level;
}