#include "MyFunctions.h"
#include <string>
#include <iostream>

using namespace std;

//학생 정보 입력
void InputStudentInfo(string** arr, int row, int col) 
{
	cout << "이름 나이 생일을 순서대로 입력하세요. \n";
	cout << "ex) 장서영 25 0221\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}

	}
}

//학생 정보 출력

void PrintStudentInfo(string** arr, int row, int col) 
{
	cout << "\n학생 정보 출력 \n\n";
	cout << "이름\t나이\t생일\n";
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
	//평균 나이 계산
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

	//가장 빠른 생일 계산
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
