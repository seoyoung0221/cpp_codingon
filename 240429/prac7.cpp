// 240429
// vector (reserve �ð� ���� ���)

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
	vector<int> test_vec1(1), test_vec2(2);
	clock_t start1, end1, start2, end2;
	double result1, result2;

	cout << "ù��° ��� ����\n";
	start1 = clock();
	for (int i = 0; i < 100000000; i++)
	{
		test_vec1.push_back(i);
	}
	end1 = clock();
	result1 = double(end1 - start1);
	cout << "ù��° ��� �ð��� " << result1 << "ms �Դϴ�. \n\n";


	cout << "�ι�° ��� ����\n";
	start2 = clock();
	test_vec2.reserve(100000000);
	for (int i = 0; i < 100000000; i++)
	{
		test_vec2.push_back(i);
	}
	end2 = clock();
	result2 = double(end2 - start2);
	cout << "�ι�° ��� �ð��� " << result2 << "ms �Դϴ�.";

	return 0;
}
