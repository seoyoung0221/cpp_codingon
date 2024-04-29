//240429
//2���� �迭, �����迭

#include <iostream>

using namespace std;

int main()
{
	int input1, input2;
	
	//��� �� �Է� �ޱ�
	cout << "��� ���� ���� �Է��ϼ��� : ";
	cin >> input1 >> input2;

	//2���� �迭 ����
	int** arr = new int* [input1];

	for (int i = 0; i < input1; i++)
	{
		arr[i] = new int[input2];
	}

	//��� ���� �Է� �ޱ�
	cout << "��� ���Ҹ� �Է��ϼ��� : ";
	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << "\n";

	//��� �����ֱ�
	cout << "���� ��� \n";
	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n"; 

	//sum1 : ���� ���� �����س��� ���
	//sum2 : ���� ���� �����س��� ���
	int* sum1 = new int[input1];
	int* sum2 = new int[input2];

	//���� �� ���
	for (int i = 0; i < input1; i++)
	{
		sum1[i] = 0;
	}

	for (int i = 0; i < input2; i++)
	{
		sum2[i] = 0;
	}
	
	//���� �� ���
	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			sum1[i] += arr[i][j];
		}
	}

	for (int i = 0; i < input2; i++)
	{
		for (int j = 0; j < input1; j++)
		{
			sum2[i] += arr[j][i];
		}
	}

	// ���� ��, ���� �� ���
	cout << "�� ���� �� \n";

	for (int i = 0; i < input1; i++)
	{
		cout << i + 1 << "���� �� : " << sum1[i] << "\n";
	}
	cout << "\n";
	cout << "�� ���� �� \n";

	for (int i = 0; i < input2; i++)
	{
		cout << i + 1 << "���� �� : " << sum2[i] << "\n";
	}

	//���� �Ҵ� ����
	delete[] sum1;
	delete[] sum2;
	
	for (int i = 0; i < input2; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}