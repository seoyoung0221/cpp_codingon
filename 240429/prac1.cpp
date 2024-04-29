//240429
//list

#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> myList = { 5,4,3,4,2,1,1 };
	cout << "현재 리스트 출력\n";
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	// 4가 몇 개인지 출력
	int cnt = 0;
	cout << "4가 몇 개인지 출력 \n";
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		if (*it == 4)
		{
			cnt++;
		}
	}
	cout << "4의 갯수는 " << cnt << "입니다. \n\n";

	// 리스트 오름차순으로 정렬 및 출력
	myList.sort();
	
	cout << "리스트를 오름차순으로 정렬 \n";
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	// 중복된 요소 제거 및 출력
	myList.unique();

	cout << "리스트의 중복된 요소 제거 \n";
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	// {6, 7} 추가 및 출력
	list<int> addList1 = { 6,7 };
	myList.splice(myList.end(), addList1);

	cout << "리스트에 {6, 7}추가 \n";

	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n\n";

	// {0} 추가 및 출력
	list<int> addList2 = { 0 };
	myList.merge(addList2);

	cout << "리스트에 {0}추가 \n";

	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";
	}

	cout << "\n\n";

	return 0;
}