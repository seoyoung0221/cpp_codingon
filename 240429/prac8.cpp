// 240429
// vector 중복삭제
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> myVector = { 10,20, 30, 20, 40, 10, 50 };

	//기존 벡터 출력
	cout << "before : v = {";
	for (int i = 0; i < myVector.size(); i++)
	{
		if (i == myVector.size() - 1)
		{
			cout << myVector.at(i);
		}
		else
		{
			cout << myVector.at(i) << ", ";
		}
	}

	cout << "} \n";

	//중복 문자 삭제
	sort(myVector.begin(), myVector.end());
	myVector.erase(unique(myVector.begin(), myVector.end()), myVector.end());

	//삭제 후 벡터 출력
	cout << "after : v = {";
	for (int i = 0; i < myVector.size(); i++)
	{
		if (i == myVector.size() - 1)
		{
			cout << myVector.at(i);
		}
		else
		{
			cout << myVector.at(i) << ", ";
		}
	}
	cout << "}";

	return 0;
}