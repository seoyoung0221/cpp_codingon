//240507
//prac1 ȸ�� ��� �ۼ��ϱ�


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string member[3][2];

	cout << "�̸� ��й�ȣ�� ������� �Է����ּ��� \n";

	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "�� ȸ�� : ";
		for (int j = 0; j < 2; j++)
		{
			cin >> member[i][j];
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