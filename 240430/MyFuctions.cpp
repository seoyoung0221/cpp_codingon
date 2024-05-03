#include "MyFunctions.h"
#include <string>
#include <iostream>

using namespace std;

void PrintStudentInfo(string** arr, int row, int col) 
{
	cout << "\n학생 정보 출력 \n\n";
	cout << "이름\t나이\t생일\n";
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

}
