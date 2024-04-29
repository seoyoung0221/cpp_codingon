//240429
//list

#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> myList = { 5,4,3,4,2,1,1 };

	// 4�� �� ������ ���
	int cnt = 0;
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		if (*it == 4)
		{
			cnt++;
		}
	}
	cout << "4�� ������ " << cnt << "�Դϴ�. \n";

	// ����Ʈ ������������ ���� �� ���
	myList.sort();
	
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	// �ߺ��� ��� ���� �� ���
	myList.unique();

	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	// {6, 7} �߰� �� ���
	list<int> addList1 = { 6,7 };
	myList.merge(addList1);


	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	// {0} �߰� �� ���
	list<int> addList2 = { 0 };
	myList.merge(addList2);


	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}

	cout << "\n";

	return 0;
}