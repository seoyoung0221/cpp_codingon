//240507
//prac2 ȸ�� ��θ� ������ �α��� ���

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Login_Func.h"


using namespace std;

bool CompareString(string my_info, string user_info);
int LogIn(string** array);

bool FindMem(string name);
void AddTel(string name);
void EditTel(string name);

/*
�弭�� 000000 
ȫ�浿 111111 
��ö�� 098765 
*/

int main() {
	int memRow = 0; // ȸ���� = �迭�� ROW
	int memCol = 2;
	int option = 0; // ���� �ɼ�
	int mem_index = -1;
	bool quit = false;

	//���� �о����
	ifstream read_file("member.txt");

	if (read_file.is_open() == false)
	{
		cout << "������ ������ �ʾҽ��ϴ�.";
		return 0;
	}

	string line1;
	int loop_cnt = 0;

	// ȸ�� �� �ľ�
	while (getline(read_file, line1))
	{
		memRow++;
	}

	// �迭 ����
	string** member = new string * [memRow];

	for (int i = 0; i < memRow; i++)
	{
		member[i] = new string[memCol];
	}

	// �迭 �ʱ�ȭ
	for (int i = 0; i < memRow; i++)
	{
		for (int j = 0; j < memCol; j++)
		{
			member[i][j] = '0';
		}
	}
	read_file.clear();
	read_file.seekg(0, ios::beg);

	//�� �� �� �޾ƿ���
	while (getline(read_file, line1))
	{
		istringstream line2(line1);
			
		// �̸��� ��й�ȣ �и�
		for (int i = 0; i < 2; i++)
		{
			line2 >> member[loop_cnt][i];
		}
		loop_cnt++;
	}

	read_file.close();
	
	cout << "���Ͻô� ����� ������. \n";
	cout << "1. �α����ϰ� ��ȭ��ȣ �Է�(����) 2. ȸ�������ϱ� 3. ��й�ȣ���� 4. ���α׷� ���� \n";
	cin >> option;
	while (true) {
		switch (option)
		{
		case 1:
			mem_index = LogIn(member);
			//member_tel�� ����� �ִ� �� Ȯ��
			if (FindMem(member[mem_index][0]) == true) {
				//��ȭ��ȣ ����
				EditTel(member[mem_index][0]);
			}
			else {
				//��ȭ��ȣ �߰�
				AddTel(member[mem_index][0]);
			}
		case 2:
		case 3:
		case 4:
			break;
		}
	}
	

	//���� �迭 ����
	for (int i = 0; i < memCol; i++)
	{
		delete[] member[i];
	}

	delete[] member;

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

// �α��� �Լ�
int LogIn(string** array) {
	string name, password;
	int Row = sizeof(array) / sizeof(array[0]);
	int Col = sizeof(array[0]) / sizeof(array[0][0]);
	int same_name = 0;
	int index = -1;

	cout << "�̸��� �Է��ϼ��� : ";

	while (same_name == 0)
	{
		cin >> name;

		for (int i = 0; i < Row; i++)
		{
			if (CompareString(array[i][0], name)) {
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

		if (CompareString(array[index][1], password))
		{
			cout << "�α��ο� �����߽��ϴ�. \n\n";
			break;
		}
		else
		{
			cout << "�ٽ� �Է����ּ��� : ";
		}
	}

	return index;
}

// member_tel�� �̸��� �����ϴ��� Ȯ��
bool FindMem(string name)
{
	ifstream read_file("member_tel.txt");
	string line;
	int loop_cnt = 0;

	while (getline(read_file, line))
	{
		if (line.find(name) == 0)
		{
			read_file.close();
			return true;
		}
	}

	read_file.close();

	return false;
}

// �̸�, ��ȭ��ȣ �߰�
void AddTel(string name)
{
	string tel;
	cout << "��ȭ��ȣ�� �Է��ϼ���. \nex) 010-1111-2222\n";
	cin >> tel;

	ofstream write_file("member_tel.txt",ios_base::app);

	if (write_file.is_open() == false)
	{
		cout << "������ ������ �ʾҽ��ϴ�.";
	}

	write_file << "\n" << name << " " << tel;

	write_file.close();
}

// ��ȭ��ȣ ����
void EditTel(string name) {
	string file_name, file_tel;
	string tel;
	int Row = 0; // ȸ���� = �迭�� ROW
	int Col = 2; // �̸�, ��ȭ��ȣ

	//���� �о����
	ifstream read_file("member_tel.txt");
	string line;
	int loop_cnt = 0;

	// ȸ�� �� �ľ�
	while (getline(read_file, line))
	{
		Row++;
	}

	// �迭 ����
	string* member = new string [Row];

	read_file.clear();
	read_file.seekg(0, ios::beg);

	//�� �� �� �޾ƿ���
	while (getline(read_file, line))
	{
		if (line.find(name) == 0)
		{
			cout << "������ ��ȭ��ȣ�� �Է��ϼ���. \nex) 010-1111-2222\n";
			cin >> tel;
			member[loop_cnt] = name + ' ' + tel;
		}
		else
		{
			member[loop_cnt] = line;
		}
		loop_cnt++;
	}
	read_file.close();

	ofstream write_file("member_tel.txt");

	for (int i = 0; i < Row; i++)
	{
		write_file << member[i] << "\n";
	}

	write_file.close();

	//���� �迭 ����
	delete[] member;
}

