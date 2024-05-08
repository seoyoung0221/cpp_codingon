//240507
//prac2 ȸ�� ��θ� ������ �α��� ���

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool CompareString(string my_info, string user_info);
bool FindMem(string name);
void AddTel(string name);
void EditTel(string name);

/*
�弭�� 000000 
ȫ�浿 111111 
��ö�� 098765 
*/

int main() {
	string name;
	string password;
	int memRow = 0; // ȸ���� = �迭�� ROW
	int memCol = 2;

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
	/*
	int option = 0;
	cout << "���Ͻô� ����� ������. \n";
	cout << "1. �α����ϱ� 2. ȸ�������ϱ� 3. ���α׷� ���� \n";
	cin >> option;
	*/
	
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
			cout << "�α��ο� �����߽��ϴ�. \n\n";
			break;
		}
		else
		{
			cout << "�ٽ� �Է����ּ��� : ";
		}
	}

	//member_tel�� ����� �ִ� �� Ȯ��
	if (FindMem(member[index][0]) == true) {
		//��ȭ��ȣ ����
		EditTel(member[index][0]);
	}
	else {
		//��ȭ��ȣ �߰�
		AddTel(member[index][0]);
	}

	//���� �迭 ����
	for (int i = 0; i < memCol; i++)
	{
		delete[] member[i];
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
	int memRow = 0; // ȸ���� = �迭�� ROW
	int memCol = 2; // �̸�, ��ȭ��ȣ

	//���� �о����
	ifstream read_file("member_tel.txt");
	string line;
	int loop_cnt = 0;

	// ȸ�� �� �ľ�
	while (getline(read_file, line))
	{
		memRow++;
	}

	// �迭 ����
	string* member = new string [memRow];

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

	for (int i = 0; i < memRow; i++)
	{
		write_file << member[i] << "\n";
	}

	write_file.close();




	//���� �迭 ����
	delete[] member;


}
