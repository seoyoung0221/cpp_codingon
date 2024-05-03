//240430
//string
#include <iostream>
#include <string>
#include "MyFunctions.h"

using namespace std;

int main() {
	float student_num;

	cout << "몇 명의 학생을 입력할 것인가요? ";
	cin >> student_num;

	string** info = new string* [student_num];

	for (int i = 0; i < student_num; i++)
	{
		info[i] = new string[3];
	}

	cout << "이름 나이 생일을 순서대로 입력하세요. \n";
	cout << "ex) 장서영 25 0221\n";
	for (int i = 0; i < student_num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> info[i][j];
		}
	}

	//학생 정보 출력
	PrintStudentInfo(info, student_num, 3);


	//평균 나이 계산

	float age_sum = 0;
	float age_avg = 0;
	
	for (int i = 0; i < student_num; i++)
	{
		age_sum += stoi(info[i][1]);
	}

	age_avg = age_sum / student_num;
	cout << "평균 나이는 " << age_avg << "입니다. \n\n";

	//가장 빠른 생일 
	int fast_birthday = INT32_MAX;
	int fast_birthday_index = -1;

	for (int i = 0; i < student_num; i++)
	{
		if (fast_birthday > stoi(info[i][2])) {
			fast_birthday = stoi(info[i][2]);
			fast_birthday_index = i;
		}
	}

	cout << "가장 빠른 생일은 " << info[fast_birthday_index][2] << "입니다. \n";

	//동적 배열 해제
	for (int i = 0; i < student_num; i++)
	{
		delete[] info[i];
	}

	delete[] info;

	return 0;
}