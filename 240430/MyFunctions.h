#pragma once
#include <string>
#include <iostream>

using namespace std;

void InputStudentInfo(string** arr, int row, int col);
void PrintStudentInfo(string** arr, int row, int col);


namespace Calculate
{
	float CalAgeAvg(string** arr, int row, int col);
	int CalBirthday(string** arr, int row, int col);
}