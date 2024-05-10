//240510
//���� ĳ���� �����ϱ�

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
		cout << "���ϴ� �޴��� �����ϼ���.\n";
		cout << "1. �̸� ���� 2. level up 3. item �ݱ� 4. item ��� 5. ���� ���� ��� 0. ���� ����\n" ;
		cin >> option;
		switch (option)
		{
		case 0 :
		{
			cout << "������ �����մϴ�. ";
			break;
		}
		case 1:
		{
			cout << "������ �̸��� �Է����ּ���. \n";
			cin >> name;
			character.setChangeName(name);
			cout << "�̸��� ����Ǿ����ϴ�.\n";
			break;
		}
		case 2 :
		{
			cout << "level up! \n";
			character.setLevelUp();
			cout << "���� ������ " << character.getLevel() << "�� �Դϴ�.\n";
			break;
		}
		case 3 :
		{
			cout << "item�� �ֿ����ϴ�. \n";
			character.setPickUpItem();
			cout << "���� ������ ���� " << character.getItemNum() << "�Դϴ�.\n";
			break;
		}
		case 4 :	
		{
			if (character.getItemNum() > 0)
			{
				cout << "item�� ����߽��ϴ�. \n";
				character.setUseItem();
				cout << "���� ������ ���� " << character.getItemNum() << "�Դϴ�.\n";
			}
			else {
				cout << "����� �������� �����ϴ�. \n";
			}

			break;
		}
		case 5:
		{
			cout << "--------���� ����--------\n";
			cout << "�̸� : " << character.getName() << "\n";
			cout << "���� : " << character.getLevel() << "\n";
			cout << "������ �� : " << character.getItemNum() << "\n";
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
