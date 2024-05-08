//240507
//prac2 회원 명부를 응용한 로그인 기능

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

bool CompareString(string my_info, string user_info);

int main() {
	string name;
	string password;
	string member[3][2];

	//파일 읽어오기
	ifstream read_file("member.txt");


	if (read_file.is_open())
	{
		string line1;
		int loop_cnt = 0;
		while (getline(read_file, line1))
		{
			istringstream line2(line1);
			
			for (int i = 0; i < 2; i++)
			{
				line2 >> member[loop_cnt][i];
			}
			loop_cnt++;
		}

	}

	read_file.close();
	int same_name = 0;
	int index = -1;

	cout << "이름을 입력하세요 : ";

	while (same_name == 0)
	{
		cin >> name;
		
		for (int i = 0; i < 3; i++)
		{
			if (CompareString(member[i][0], name)) {
				same_name = 1;
				index = i;
				break;
			}
		}

		if (same_name == 0)
		{
			cout << "다시 입력해주세요 : ";
		}
	}

	cout << "비밀번호를 입력하세요 : ";
	while (true)
	{
		cin >> password;

		if (CompareString(member[index][1], password))
		{
			cout << "로그인에 성공했습니다. \n";
			break;
		}
		else
		{
			cout << "다시 입력해주세요 : ";
		}
	}

	return 0;
}

// 문자열 비교하는 함수
bool CompareString(string my_info, string user_info)
{
	//my_info : 내가 가지고 있는 정보, user_info : 사용자가 전해준 정보
	if (my_info.compare(user_info) == 0)
	{
		return true;
	}

	return false;
}