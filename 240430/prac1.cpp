// 240430
// string

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";
	cout << s << "\n";

	//s 문자열의 길이 출력
	cout << "s의 길이 : " << s.length() << "\n";

	//100번째 문자 출력
	cout << "100번째 문자 : " << s[100] << "\n";

	//two라는 문자가 처음 나오는 index 출력
	cout << "two가 처음 나온 index : " << s.find("two") << "\n";

	//two라는 문자가 두번째 나오는 index 출력
	cout << "two가 처음 나온 index : " << s.find("two", 12);



	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
