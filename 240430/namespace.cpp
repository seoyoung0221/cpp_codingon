#include <iostream>
#include <string>
#include "MyFunctions.h"

using namespace std;
using namespace Calculate;

int main()
{
	float student_num;
	cout << "몇 명의 학생을 입력할 것인가요? ";
	cin >> student_num;

	string** student = new string * [student_num];

	for (int i = 0; i < student_num; i++)
	{
		student[i] = new string[3];
	}

	InputStudentInfo(student, student_num, 3);

	float avg = CalAgeAvg(student, student_num, 3);

	cout <<"나이 평균은 " << avg << "입니다.";

	return 0;
}
