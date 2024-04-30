//240430
//string

#include <iostream>
#include <string>

using namespace std;

int check_num(string);


int main() {
	string sentence1, sentence2;

	int test = 0; 

	cout << "두 문장을 입력해주세요.\n";

	while (test == 0) {
		getline(cin, sentence1);
		getline(cin, sentence2);
		
		if (check_num(sentence1) == 1 && check_num(sentence2) == 1)
		{
			cout << "둘 다 숫자임 \n";
			test = 1;
		}
		else {
			cout << "다시 입력해주세요. \n";
		}

	}

	//두 개의 숫자를 이어 붙여 출력
	string append_sentence;

	append_sentence = sentence1.append(sentence2);
	cout << "두 개의 숫자를 이어 붙이기 : " << append_sentence << "\n";

	//두 숫자 합 출력
	int sum = 0;

	// 이어 붙인 부분 제거
	int find_sentence2 = sentence1.find(sentence2);
	sentence1.resize(find_sentence2);

	sum = stoi(sentence1) + stoi(sentence2);
	cout << "두 숫자의 합 : " << sum;


	return 0;
}


int check_num(string str) {
	//숫자면 양수, 문자면 0
	int is_num= 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]) == 0) {
			//str이 문자임
			is_num += 0;
		}
		else {
			//str이 숫자임
			is_num += 1;
		}
	}


	if (is_num == 0)
	{
		return 0;
	}
	else {
		return 1;
	}

}
