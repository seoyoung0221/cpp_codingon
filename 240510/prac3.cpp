//240510
//게임 캐릭터 생성하기

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

	int monster_level; //monster의 level 입력받는 변수
	bool pass = true;

	std::srand(time(NULL));
	int randomItemNum = 0; //몬스터와 전투 후 얻는 아이템의 수 

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
			cout << "게임을 종료합니다. ";
			break;
		}
		case 1:
		{
			cout << "변경할 이름을 입력해주세요. \n";
			cin >> player_name;
			character.setChangeName(player_name);
			cout << "이름이 변경되었습니다.\n";
			break;
		}
		case 2 :
		{
			character.setLevelUp();
			cout << "현재 레벨은 " << character.getLevel() << "입니다.\n";
			break;
		}
		case 3 :
		{
			cout << "item을 주웠습니다. \n";
			character.setPickUpItem();
			cout << "현재 아이템 수는 " << character.getItemNum() << "개 입니다.\n";
			break;
		}
		case 4 :	
		{
			if (character.getItemNum() > 0)
			{
				cout << "item을 사용했습니다. \n";
				character.setUseItem();
				cout << "현재 아이템 수는 " << character.getItemNum() << "개 입니다.\n";
			}
			else {
				cout << "사용할 아이템이 없습니다. \n";
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
			cout << "몬스터와 싸웁니다. \n" << "몬스터의 레벨을 입력하세요. \n";
			cin >> monster_level;
			monster.setLevel(monster_level);
			monster.ShowMonsterInfo();

			while (monster.getHP() != 0 && character.getHP() != 0)
			{
				cout << "몬스터를 공격합니다. \n\n";
				cout << "몬스터의 체력 : " << monster.getHP() << " -> ";
				monster.setloseHP(character.getPower());
				cout << monster.getHP() << "\n\n";

				if (monster.getHP() == 0) {
					break;
				}

				cout << character.getName() << "을(를) 공격합니다. \n\n";
				cout << "플레이어의 체력 : " << character.getHP() << " -> ";
				character.setloseHP(monster.getPower());
				cout << character.getHP() << "\n";
			}

			if (monster.getHP() == 0) 
			{
				cout << "몬스터를 이겼습니다. \n";
				character.setEXP(monster_level);
				randomItemNum = std::rand() % 3 + 1;
				for (int i = 0; i < randomItemNum; i++)
				{
					character.setPickUpItem();
				}
				cout << "아이템을 " << randomItemNum << "개 주웠습니다. \n\n";

			}
			else if (character.getHP() == 0)
			{
				cout << "몬스터에게 졌습니다. \n";
				cout << "프로그램이 종료되었습니다. \n";
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
		cout << "원하는 메뉴를 선택하세요.\n";
		cout << "1. 이름 변경 2. level up 3. item 줍기 4. item 사용 5. 현재 상태 출력 \n6. 체력 회복하기 7. 몬스터와 싸우기 8. 플레이어 정보 저장 0. 게임 종료\n";
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
			cout << "잘못된 입력입니다. \n";
	}
	return option;
}

bool findNumber(string str)
{

	for (char& c : str)
	{
		// 숫자면 0이 아님
		// 숫자일 때 true 리턴
		if (isdigit(c) != 0)
		{
			return true;
		}
	}

	return false;
}