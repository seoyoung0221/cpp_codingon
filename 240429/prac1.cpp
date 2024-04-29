//240429
//list

#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> myList = { 5,4,3,4,2,1,1 };

	// 4가 몇 개인지 출력
	int cnt = 0;
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		if (*it == 4)
		{
			cnt++;
		}
	}
	cout << "4의 갯수는 " << cnt << "입니다. \n";

	// 리스트 오름차순으로 정렬 및 출력
	myList.sort();
	
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	// 중복된 요소 제거 및 출력
	myList.unique();

	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	// {6, 7} 추가 및 출력
	list<int> addList1 = { 6,7 };
	myList.merge(addList1);


	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	// {0} 추가 및 출력
	list<int> addList2 = { 0 };
	myList.merge(addList2);


	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}

	cout << "\n";

	return 0;
}