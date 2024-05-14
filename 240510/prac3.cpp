//240510
//���� ĳ���� �����ϱ�

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include<vector>
#include "Character.h"
#include "Monster.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

string InputOption();
bool findNumber(string str);

int main() {
	//Character character{ "sy" };
	int option = -1;
	string player_name;
	int player_level, player_item_num, player_HP, player_EXP;
	vector<string> Info;

	Monster monster{};

	int monster_level; //monster�� level �Է¹޴� ����
	bool pass = true;

	std::srand(time(NULL));
	int randomItemNum = 0; //���Ϳ� ���� �� ��� �������� �� 

	ifstream readFile;
	readFile.open("player.txt");

	if (!readFile.is_open()) return -1;
	while (!readFile.eof()) {
		string tmp;
		getline(readFile, tmp);
		Info.push_back(tmp);
	}

	player_name = Info[0];
	Character character(Info[0], stoi(Info[1]), stoi(Info[2]), stoi(Info[3]), stoi(Info[4]));

	readFile.close();

	while (option != 0)
	{
		option = stoi(InputOption());

		switch (option)
		{
		case 0:
		{
			cout << "������ �����մϴ�. ";
			break;
		}
		case 1:
		{
			cout << "������ �̸��� �Է����ּ���. \n";
			cin >> player_name;
			character.setChangeName(player_name);
			cout << "�̸��� ����Ǿ����ϴ�.\n";
			break;
		}
		case 2 :
		{
			character.setLevelUp();
			cout << "���� ������ " << character.getLevel() << "�Դϴ�.\n";
			break;
		}
		case 3 :
		{
			cout << "item�� �ֿ����ϴ�. \n";
			character.setPickUpItem();
			cout << "���� ������ ���� " << character.getItemNum() << "�� �Դϴ�.\n";
			break;
		}
		case 4 :	
		{
			if (character.getItemNum() > 0)
			{
				cout << "item�� ����߽��ϴ�. \n";
				character.setUseItem();
				cout << "���� ������ ���� " << character.getItemNum() << "�� �Դϴ�.\n";
			}
			else {
				cout << "����� �������� �����ϴ�. \n";
			}

			break;
		}
		case 5:
		{
			character.ShowCharacterInfo();
			break;
		}
		case 6 :
		{
			character.setRestoreHP();
			break;
		}
		case 7 :
		{
			cout << "���Ϳ� �ο�ϴ�. \n" << "������ ������ �Է��ϼ���. \n";
			cin >> monster_level;
			monster.setLevel(monster_level);
			monster.ShowMonsterInfo();

			while (monster.getHP() != 0 && character.getHP() != 0)
			{
				cout << "���͸� �����մϴ�. \n\n";
				cout << "������ ü�� : " << monster.getHP() << " -> ";
				monster.setloseHP(character.getPower());
				cout << monster.getHP() << "\n\n";

				if (monster.getHP() == 0) {
					break;
				}

				cout << character.getName() << "��(��) �����մϴ�. \n\n";
				cout << "�÷��̾��� ü�� : " << character.getHP() << " -> ";
				character.setloseHP(monster.getPower());
				cout << character.getHP() << "\n";
			}

			if (monster.getHP() == 0) 
			{
				cout << "���͸� �̰���ϴ�. \n";
				character.setEXP(monster_level);
				randomItemNum = std::rand() % 3 + 1;
				for (int i = 0; i < randomItemNum; i++)
				{
					character.setPickUpItem();
				}
				cout << "�������� " << randomItemNum << "�� �ֿ����ϴ�. \n\n";

			}
			else if (character.getHP() == 0)
			{
				cout << "���Ϳ��� �����ϴ�. \n";
				cout << "���α׷��� ����Ǿ����ϴ�. \n";
				option = 0;
			}
			break;
		}

		case 8: 
		{
			ofstream writeFile;
			writeFile.open("player.txt");

			if (writeFile.is_open()) {
				writeFile << character.getName() << "\n" << character.getLevel() << "\n" << character.getItemNum()
					<< "\n" << character.getHP() << "\n" << character.getEXP() << "\n";
			}

			writeFile.close();
			break;
		}

		default:
			break;
		}
		cout << "\n";
	}

	return 0;
}

string InputOption()
{
	string option;
	while (true)
	{
		cout << "���ϴ� �޴��� �����ϼ���.\n";
		cout << "1. �̸� ���� 2. level up 3. item �ݱ� 4. item ��� 5. ���� ���� ��� \n6. ü�� ȸ���ϱ� 7. ���Ϳ� �ο�� 8. �÷��̾� ���� ���� 0. ���� ����\n";
		cin >> option;

		bool checkOptionLength = false;
		if (option.length() == 1)
			checkOptionLength = true;

		bool checkOptionInt = false;
		bool checkOptionSize = false;

		if (findNumber(option))
		{
			checkOptionInt = true;

			if (stoi(option) <= 8 && stoi(option) >= 0)
				checkOptionSize = true;
		}

		if (checkOptionLength && checkOptionSize && checkOptionSize)
			break;
		else
			cout << "�߸��� �Է��Դϴ�. \n";
	}
	return option;
}

bool findNumber(string str)
{

	for (char& c : str)
	{
		// ���ڸ� 0�� �ƴ�
		// ������ �� true ����
		if (isdigit(c) != 0)
		{
			return true;
		}
	}

	return false;
}