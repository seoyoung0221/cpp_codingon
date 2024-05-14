#include "Character.h"

string Character::getName() { return m_name; }
int Character::getLevel() { return m_level; }
int Character::getItemNum() { return m_item_num; }
int Character::getPower() { return m_power; }
int Character::getHP() { return m_HP; }
int Character::getEXP() { return m_EXP; }


void Character::ShowCharacterInfo() {

	cout << "--------현재 상태--------\n";
	cout << "이름 : " << m_name << "\n";
	cout << "레벨 : " << m_level << "\n";
	cout << "아이템 수 : " << m_item_num << "\n";
	cout << "현재 HP : " << m_HP << "\n";
	cout << "현재 EXP : " << m_EXP << "\n";
	cout << "------------------------\n";

}

//이름 변경 함수
void Character::setChangeName(string name)
{
	this->m_name = name;
}

//레벨업 함수
//1번 경우 : 사용자가 직접 레벨 올리는 경우
//2번 경우 : 경험치가 max되어 레벨이 올라간 경우

void Character::setLevelUp()
{
	this->m_level++;
	this->m_max_HP += 10;
	this->m_HP += m_max_HP;
	this->m_power += 20;
	cout << "level up! \n";
}

//아이템 얻기 함수
void Character::setPickUpItem() {
	this->m_item_num++;
}

//아이템 사용 함수
void Character::setUseItem() {
	this->m_item_num--;
}

//공격받아 HP가 깎이는 함수
void Character::setloseHP(int attack) {
	if (m_HP - attack <= 0)
	{
		this->m_HP = 0;
	}
	else {
		this->m_HP -= attack;
	}
}

//HP 회복 함수
void Character::setRestoreHP() 
{
	if (m_HP + 10 <= m_max_HP) {
		this->m_HP += 10;
	}
	else
	{
		cout << "더이상 회복할 HP가 없습니다. \n";
	}
}

//EXP 획득함수 & exp가 1000보다 클 시 levelup
void Character::setEXP(int monsterLevel) {
	this->m_EXP += monsterLevel * 10;
		if (this->m_EXP >= this->m_max_EXP) {
			setLevelUp();
			m_EXP = 0;
		}
	cout << "현재 경험치 : " << m_EXP * 10 << "\n";
}