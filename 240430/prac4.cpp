//240430
//string
#include <iostream>
#include <string>
#include "MyFunctions.h"

using namespace std;

int main() {
	float student_num;
	int option;

	cout << "몇 명의 학생을 입력할 것인가요? ";
	cin >> student_num;

	string** info = new string* [student_num];

	for (int i = 0; i < student_num; i++)
	{
		info[i] = new string[3];
	}

	//학생 정보 입력
	InputStudentInfo(info, student_num, 3);

	cout << "원하는 옵션을 선택하세요. \n";
	cout << "1. 학생 정보 출력 2. 평균 나이 계산 3. 가장 빠른 생일 계산 4. 프로그램 종료\n";
	cin >> option;

	float age_avg = 0;
	int fast_birthday_index = -1;

	while (option != 4)
	{
		switch(option){
		case 1 : 
			//학생 정보 출력
			PrintStudentInfo(info, student_num, 3);
			break;
		case 2 :
			//평균 나이 계산
			age_avg = CalAgeAvg(info, student_num, 3);
			cout << "평균 나이는 " << age_avg << "입니다. \n\n";
			break;
		case 3 :
			//가장 빠른 생일 
			fast_birthday_index = CalBirthday(info, student_num, 3);
			cout << "가장 빠른 생일은 " << info[fast_birthday_index][2] << "입니다. \n";
			break;
		}
		cout << "\n원하는 옵션을 선택하세요. \n";
		cout << "1. 학생 정보 출력 2. 평균 나이 계산 3. 가장 빠른 생일 계산 4. 프로그램 종료\n";
		cin >> option;
	}


	cout << "프로그램을 종료합니다. \n";
	//동적 배열 해제
	for (int i = 0; i < student_num; i++)
	{
		delete[] info[i];
	}

	delete[] info;

	return 0;
}