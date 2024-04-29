// 240429
// vector 중복삭제
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> myVector = { 10,20, 30, 20, 40, 10, 50 };

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

	sort(myVector.begin(), myVector.end());
	myVector.erase(unique(myVector.begin(), myVector.end()), myVector.end());

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