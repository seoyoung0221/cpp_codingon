//240507
//prac1 ȸ�� ��� �ۼ��ϱ�

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int CountWord(string info);
bool CheckInputLength(string info);

int main() {
	string member[3][2];
	string line;
	cout << "�̸� ��й�ȣ(6~18�ڸ�)�� ������� �Է����ּ��� \n";

	int n = 0;

	while(true)
	{
		int blank_cnt = 0;

		cout << n+1 << "�� ȸ�� : ";
		getline(cin, line);

		if (CountWord(line) == 2 && CheckInputLength(line) == true)
		{
			int blank_index = line.find(' ');
			member[n][0] = line.substr(0, blank_index);
			member[n][1] = line.substr(blank_index+1);
			n++;
		}
		else 
		{
			cout << "�ٽ� �Է����ּ��� : ";
		}

		if (n == 3)
		{
			break;
		}
	}

	ofstream write_file("member.txt");

	//output ���Ͽ� ���� ����
	if (write_file.is_open()) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				write_file << member[i][j] << "\t";
			}
			write_file << "\n";
		}
	}

	//output ���� �ݱ�
	write_file.close();

	//���� �о����
	ifstream read_file("member.txt");

	int lineCnt = 0;
	vector<string> v;

	if (read_file.is_open())
	{
		string line;
		//EOF
		while (getline(read_file, line))
		{
			lineCnt++;
			v.push_back(line);
		}
	}

	read_file.close();

	for (int i = 0; i < lineCnt; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}

int CountWord(string info)
{
	int word_cnt = 1;
	for (int i = 0; i < info.length(); i++)
	{
		if (info[i] == ' ')
		{
			word_cnt++;
		}
	}
	return word_cnt;
}

bool CheckInputLength(string info)
{
	//���̰� 6~18�ڸ��̸� true �ƴϸ� false
	if (info.length() >= 6 && info.length() <= 18)
	{
		return true;
	}

	return false;
}
