#include "MyFunctions.h"
#include <string>
#include <iostream>

using namespace std;

void PrintStudentInfo(string** arr, int row, int col) 
{
	cout << "\n�л� ���� ��� \n\n";
	cout << "�̸�\t����\t����\n";
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

}
