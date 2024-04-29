//240429
//list

#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> myList = { 5,4,3,4,2,1,1 };
	cout << "���� ����Ʈ ���\n";
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	// 4�� �� ������ ���
	int cnt = 0;
	cout << "4�� �� ������ ��� \n";
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		if (*it == 4)
		{
			cnt++;
		}
	}
	cout << "4�� ������ " << cnt << "�Դϴ�. \n\n";

	// ����Ʈ ������������ ���� �� ���
	myList.sort();
	
	cout << "����Ʈ�� ������������ ���� \n";
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	// �ߺ��� ��� ���� �� ���
	myList.unique();

	cout << "����Ʈ�� �ߺ��� ��� ���� \n";
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	// {6, 7} �߰� �� ���
	list<int> addList1 = { 6,7 };
	myList.splice(myList.end(), addList1);

	cout << "����Ʈ�� {6, 7}�߰� \n";

	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	// {0} �߰� �� ���
	list<int> addList2 = { 0 };
	myList.merge(addList2);

	cout << "����Ʈ�� {0}�߰� \n";

	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}

	cout << "\n\n";

	return 0;
}