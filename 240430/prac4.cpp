//240430
//string
#include <iostream>
#include <string>

using namespace std;

int main() {
	float student_num;

	cout << "�� ���� �л��� �Է��� ���ΰ���? ";
	cin >> student_num;

	string** info = new string* [student_num];

	for (int i = 0; i < student_num; i++)
	{
		info[i] = new string[3];
	}

	cout << "�̸� ���� ������ ������� �Է��ϼ���. \n";
	cout << "ex) �弭�� 25 0221\n";
	for (int i = 0; i < student_num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> info[i][j];
		}
	}

	//�л� ���� ���
	cout << "\n�л� ���� ��� \n\n";
	cout << "�̸�\t����\t����\n";

	for (int i = 0; i < student_num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << info[i][j] << "\t";
		}
		cout << "\n";
	}

	//��� ���� ���

	float age_sum = 0;
	float age_avg = 0;
	
	for (int i = 0; i < student_num; i++)
	{
		age_sum += stoi(info[i][1]);
	}

	age_avg = age_sum / student_num;
	cout << "��� ���̴� " << age_avg << "�Դϴ�. \n\n";

	//���� ���� ���� 
	int fast_birthday = INT16_MAX;
	int fast_birthday_index = -1;

	for (int i = 0; i < student_num; i++)
	{
		if (fast_birthday > stoi(info[i][2])) {
			fast_birthday = stoi(info[i][2]);
			fast_birthday_index = i;
		}
	}

	cout << "���� ���� ������ " << info[fast_birthday_index][2] << "�Դϴ�. \n";

	return 0;
}