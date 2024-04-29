//240429
//2차원 배열, 동적배열

#include <iostream>

using namespace std;

int main()
{
	int input1, input2;
	
	//행과 열 입력 받기
	cout << "행과 열의 수를 입력하세요 : ";
	cin >> input1 >> input2;

	//2차원 배열 선언
	int** arr = new int* [input1];

	for (int i = 0; i < input1; i++)
	{
		arr[i] = new int[input2];
	}

	//행렬 원소 입력 받기
	cout << "행렬 원소를 입력하세요 : ";
	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << "\n";

	//행렬 보여주기
	cout << "현재 행렬 \n";
	for (int i = 0; i < input1; i++)
	{
		for (int j = 0; j < input2; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n"; 

	//sum1 : 행의 합을 저장해놓은 행렬
	//sum2 : 열의 합을 저장해놓은 행렬
	int* sum1 = new int[input1];
	int* sum2 = new int[input2];

	//행의 합 계산
	for (int i = 0; i < input1; i++)
	{
		sum1[i] = 0;
	}

	for (int i = 0; i < input2; i++)
	{
		sum2[i] = 0;
	}
	
	//열의 합 계산
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

	// 행의 합, 열의 합 출력
	cout << "각 행의 합 \n";

	for (int i = 0; i < input1; i++)
	{
		cout << i + 1 << "행의 합 : " << sum1[i] << "\n";
	}
	cout << "\n";
	cout << "각 열의 합 \n";

	for (int i = 0; i < input2; i++)
	{
		cout << i + 1 << "열의 합 : " << sum2[i] << "\n";
	}

	//동적 할당 해제
	delete[] sum1;
	delete[] sum2;
	
	for (int i = 0; i < input2; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}