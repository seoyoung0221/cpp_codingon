#include "Character.h"

string Character::getName() { return m_name; }
int Character::getLevel() { return m_level; }
int Character::getItemNum() { return m_item_num; }
int Character::getPower() { return m_power; }
int Character::getHP() { return m_HP; }
int Character::getEXP() { return m_EXP; }


void Character::ShowCharacterInfo() {

	cout << "--------���� ����--------\n";
	cout << "�̸� : " << m_name << "\n";
	cout << "���� : " << m_level << "\n";
	cout << "������ �� : " << m_item_num << "\n";
	cout << "���� HP : " << m_HP << "\n";
	cout << "���� EXP : " << m_EXP << "\n";
	cout << "------------------------\n";

}

//�̸� ���� �Լ�
void Character::setChangeName(string name)
{
	this->m_name = name;
}

//������ �Լ�
//1�� ��� : ����ڰ� ���� ���� �ø��� ���
//2�� ��� : ����ġ�� max�Ǿ� ������ �ö� ���

void Character::setLevelUp()
{
	this->m_level++;
	this->m_max_HP += 10;
	this->m_HP += m_max_HP;
	this->m_power += 20;
	cout << "level up! \n";
}

//������ ��� �Լ�
void Character::setPickUpItem() {
	this->m_item_num++;
}

//������ ��� �Լ�
void Character::setUseItem() {
	this->m_item_num--;
}

//���ݹ޾� HP�� ���̴� �Լ�
void Character::setloseHP(int attack) {
	if (m_HP - attack <= 0)
	{
		this->m_HP = 0;
	}
	else {
		this->m_HP -= attack;
	}
}

//HP ȸ�� �Լ�
void Character::setRestoreHP() 
{
	if (m_HP + 10 <= m_max_HP) {
		this->m_HP += 10;
	}
	else
	{
		cout << "���̻� ȸ���� HP�� �����ϴ�. \n";
	}
}

//EXP ȹ���Լ� & exp�� 1000���� Ŭ �� levelup
void Character::setEXP(int monsterLevel) {
	this->m_EXP += monsterLevel * 10;
		if (this->m_EXP >= this->m_max_EXP) {
			setLevelUp();
			m_EXP = 0;
		}
	cout << "���� ����ġ : " << m_EXP * 10 << "\n";
}