#include <iostream>
#include <string>
#include "MyFunctions.h"

using namespace std;
using namespace Calculate;

int main()
{
	float student_num;
	cout << "�� ���� �л��� �Է��� ���ΰ���? ";
	cin >> student_num;

	string** student = new string * [student_num];

	for (int i = 0; i < student_num; i++)
	{
		student[i] = new string[3];
	}

	InputStudentInfo(student, student_num, 3);

	float avg = CalAgeAvg(student, 2, 3);

	cout << avg;

	return 0;
}
