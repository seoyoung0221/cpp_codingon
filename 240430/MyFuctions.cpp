#include "MyFunctions.h"
#include <string>
#include <iostream>

using namespace std;

//�л� ���� �Է�
void InputStudentInfo(string** arr, int row, int col) 
{
	cout << "�̸� ���� ������ ������� �Է��ϼ���. \n";
	cout << "ex) �弭�� 25 0221\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}

	}
}

//�л� ���� ���

void PrintStudentInfo(string** arr, int row, int col) 
{
	cout << "\n�л� ���� ��� \n\n";
	cout << "�̸�\t����\t����\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}


namespace Calculate
{
	//��� ���� ���
	float CalAgeAvg(string** arr, int row, int col) {
		float age_sum = 0;
		float age_avg = 0;

		for (int i = 0; i < row; i++)
		{
			age_sum += stoi(arr[i][1]);
		}

		age_avg = age_sum / row;

		return age_avg;
	}

	//���� ���� ���� ���
	int CalBirthday(string** arr, int row, int col)
	{
		int fast_birthday = INT32_MAX;
		int fast_birthday_index = -1;

		for (int i = 0; i < row; i++)
		{
			if (fast_birthday > stoi(arr[i][2])) {
				fast_birthday = stoi(arr[i][2]);
				fast_birthday_index = i;
			}
		}
		return fast_birthday_index;
	}
}
