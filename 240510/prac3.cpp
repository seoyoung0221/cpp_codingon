//240510
//게임 캐릭터 생성하기

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Character
{
public:
	Character(string name): m_name(name){}

	string getName();
	int getLevel();
	int getItemNum();

	void setChangeName(string name);
	void setLevelUp(); 
	void setPickUpItem();
	void setUseItem();

private:

	string m_name;
	int m_level = 0;
	int m_item_num = 0;
};


int main() {
	Character character("sy");
	int option = -1;
	string name;

	while (option != 0)
	{
		cout << "원하는 메뉴를 선택하세요.\n";
		cout << "1. 이름 변경 2. level up 3. item 줍기 4. item 사용 5. 현재 상태 출력 0. 게임 종료\n" ;
		cin >> option;
		switch (option)
		{
		case 0 :
		{
			cout << "게임을 종료합니다. ";
			break;
		}
		case 1:
		{
			cout << "변경할 이름을 입력해주세요. \n";
			cin >> name;
			character.setChangeName(name);
			cout << "이름이 변경되었습니다.\n";
			break;
		}
		case 2 :
		{
			cout << "level up! \n";
			character.setLevelUp();
			cout << "현재 레벨은 " << character.getLevel() << "개 입니다.\n";
			break;
		}
		case 3 :
		{
			cout << "item을 주웠습니다. \n";
			character.setPickUpItem();
			cout << "현재 아이템 수는 " << character.getItemNum() << "입니다.\n";
			break;
		}
		case 4 :	
		{
			if (character.getItemNum() > 0)
			{
				cout << "item을 사용했습니다. \n";
				character.setUseItem();
				cout << "현재 아이템 수는 " << character.getItemNum() << "입니다.\n";
			}
			else {
				cout << "사용할 아이템이 없습니다. \n";
			}

			break;
		}
		case 5:
		{
			cout << "--------현재 상태--------\n";
			cout << "이름 : " << character.getName() << "\n";
			cout << "레벨 : " << character.getLevel() << "\n";
			cout << "아이템 수 : " << character.getItemNum() << "\n";
			break;
		}
		default:
			break;
		}
		cout << "\n";
	}

	return 0;
}



string Character::getName() { return m_name; }
int Character::getLevel() { return m_level; }
int Character::getItemNum() { return m_item_num; }


void Character::setChangeName(string name)
{
	this->m_name = name;
}

void Character::setLevelUp()
{
	m_level++;
}

void Character::setPickUpItem() {
	m_item_num++;
}

void Character::setUseItem() {
	m_item_num--;
}
