//240429
//2���� �迭, �����迭

#include <iostream>

using namespace std;

int main()
{
	int row, col;
	
	//��� �� �Է� �ޱ�
	cout << "��� ���� ���� �Է��ϼ��� : ";
	cin >> row >> col;

	//2���� �迭 ����
	int** arr = new int* [row];

	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}

	//��� ���� �Է� �ޱ�
	cout << "��� ���Ҹ� �Է��ϼ��� : ";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << "\n";

	//��� �����ֱ�
	cout << "���� ��� \n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n"; 

	//rowSum : ���� ���� �����س��� ���
	//colSum : ���� ���� �����س��� ���
	int* rowSum = new int[row];
	int* colSum = new int[col];

	//���� �� ���
	for (int i = 0; i < row; i++)
	{
		rowSum[i] = 0;
	}

	for (int i = 0; i < col; i++)
	{
		colSum[i] = 0;
	}
	
	//���� �� ���
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			rowSum[i] += arr[i][j];
		}
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			colSum[i] += arr[j][i];
		}
	}

	// ���� ��, ���� �� ���
	cout << "�� ���� �� \n";

	for (int i = 0; i < row; i++)
	{
		cout << i + 1 << "���� �� : " << rowSum[i] << "\n";
	}
	cout << "\n";
	cout << "�� ���� �� \n";

	for (int i = 0; i < col; i++)
	{
		cout << i + 1 << "���� �� : " << colSum[i] << "\n";
	}

	//���� �Ҵ� ����
	delete[] rowSum;
	delete[] colSum;
	
	for (int i = 0; i < col; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}