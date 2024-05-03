//240430
//string
#include <iostream>
#include <string>
#include "MyFunctions.h"

using namespace std;

int main() {
	float student_num;
	int option;

	cout << "�� ���� �л��� �Է��� ���ΰ���? ";
	cin >> student_num;

	string** info = new string* [student_num];

	for (int i = 0; i < student_num; i++)
	{
		info[i] = new string[3];
	}

	//�л� ���� �Է�
	InputStudentInfo(info, student_num, 3);

	cout << "���ϴ� �ɼ��� �����ϼ���. \n";
	cout << "1. �л� ���� ��� 2. ��� ���� ��� 3. ���� ���� ���� ��� 4. ���α׷� ����\n";
	cin >> option;

	float age_avg = 0;
	int fast_birthday_index = -1;

	while (option != 4)
	{
		switch(option){
		case 1 : 
			//�л� ���� ���
			PrintStudentInfo(info, student_num, 3);
			break;
		case 2 :
			//��� ���� ���
			age_avg = CalAgeAvg(info, student_num, 3);
			cout << "��� ���̴� " << age_avg << "�Դϴ�. \n\n";
			break;
		case 3 :
			//���� ���� ���� 
			fast_birthday_index = CalBirthday(info, student_num, 3);
			cout << "���� ���� ������ " << info[fast_birthday_index][2] << "�Դϴ�. \n";
			break;
		}
		cout << "\n���ϴ� �ɼ��� �����ϼ���. \n";
		cout << "1. �л� ���� ��� 2. ��� ���� ��� 3. ���� ���� ���� ��� 4. ���α׷� ����\n";
		cin >> option;
	}


	cout << "���α׷��� �����մϴ�. \n";
	//���� �迭 ����
	for (int i = 0; i < student_num; i++)
	{
		delete[] info[i];
	}

	delete[] info;

	return 0;
}