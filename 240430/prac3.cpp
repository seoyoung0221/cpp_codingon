//240430
//

#include <iostream>
#include <string>

using namespace std;

int main() {

	string s = "Codingon";
	cout << "s : " << s << "\n";

	//�ҹ��ڷ� ����
	s[0] = tolower(s[0]);
	cout << "s : " << s << "\n";

	//"ding"�̶�� �κй��ڿ� ��ȯ
	cout << "ding ��ȯ : " << s.substr(2, 4) << "\n";
	
	//"coooooon"�� �ǵ��� ���� 
	int num1 = s.find("o");
	int num2 = s.find("o", num1+1);
	for (int i = num1; i < num2; i++)
	{
		s.replace(i, 1, "o");
	}

	cout << s << "\n";

	//"con"�� �ǵ��� ����
	s.erase(num1, num2 - num1);
	cout << s << "\n";




	return 0;
}