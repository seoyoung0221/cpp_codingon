//240430
//

#include <iostream>
#include <string>

using namespace std;

int main() {

	string s = "Codingon";
	cout << "s : " << s << "\n";

	//소문자로 변경
	s[0] = tolower(s[0]);
	cout << "s : " << s << "\n";

	//"ding"이라는 부분문자열 반환
	cout << "ding 반환 : " << s.substr(2, 4) << "\n";
	
	//"coooooon"이 되도록 변경 
	int num1 = s.find("o");
	int num2 = s.find("o", num1+1);
	for (int i = num1; i < num2; i++)
	{
		s.replace(i, 1, "o");
	}

	cout << s << "\n";

	//"con"이 되도록 변경
	s.erase(num1, num2 - num1);
	cout << s << "\n";




	return 0;
}