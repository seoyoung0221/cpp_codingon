//240507
//prac2 ȸ�� ��θ� ������ �α��� ���

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

	//���� �о����
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

	cout << "�̸��� �Է��ϼ��� : ";

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
			cout << "�ٽ� �Է����ּ��� : ";
		}
	}

	cout << "��й�ȣ�� �Է��ϼ��� : ";
	while (true)
	{
		cin >> password;

		if (CompareString(member[index][1], password))
		{
			cout << "�α��ο� �����߽��ϴ�. \n";
			break;
		}
		else
		{
			cout << "�ٽ� �Է����ּ��� : ";
		}
	}

	return 0;
}

// ���ڿ� ���ϴ� �Լ�
bool CompareString(string my_info, string user_info)
{
	//my_info : ���� ������ �ִ� ����, user_info : ����ڰ� ������ ����
	if (my_info.compare(user_info) == 0)
	{
		return true;
	}

	return false;
}