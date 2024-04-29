//240429
//2차원 배열, 동적배열

#include <iostream>

using namespace std;

int main()
{
	int row, col;
	
	//행과 열 입력 받기
	cout << "행과 열의 수를 입력하세요 : ";
	cin >> row >> col;

	//2차원 배열 선언
	int** arr = new int* [row];

	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}

	//행렬 원소 입력 받기
	cout << "행렬 원소를 입력하세요 : ";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << "\n";

	//행렬 보여주기
	cout << "현재 행렬 \n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n"; 

	//rowSum : 행의 합을 저장해놓은 행렬
	//colSum : 열의 합을 저장해놓은 행렬
	int* rowSum = new int[row];
	int* colSum = new int[col];

	//행의 합 계산
	for (int i = 0; i < row; i++)
	{
		rowSum[i] = 0;
	}

	for (int i = 0; i < col; i++)
	{
		colSum[i] = 0;
	}
	
	//열의 합 계산
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

	// 행의 합, 열의 합 출력
	cout << "각 행의 합 \n";

	for (int i = 0; i < row; i++)
	{
		cout << i + 1 << "행의 합 : " << rowSum[i] << "\n";
	}
	cout << "\n";
	cout << "각 열의 합 \n";

	for (int i = 0; i < col; i++)
	{
		cout << i + 1 << "열의 합 : " << colSum[i] << "\n";
	}

	//동적 할당 해제
	delete[] rowSum;
	delete[] colSum;
	
	for (int i = 0; i < col; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}