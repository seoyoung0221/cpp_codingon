//240430
//string

#include <iostream>
#include <string>

using namespace std;

int check_num(string);


int main() {
	string sentence1, sentence2;

	int test = 0; 

	cout << "�� ������ �Է����ּ���.\n";

	while (test == 0) {
		getline(cin, sentence1);
		getline(cin, sentence2);
		
		if (check_num(sentence1) == 1 && check_num(sentence2) == 1)
		{
			cout << "�� �� ������ \n";
			test = 1;
		}
		else {
			cout << "�ٽ� �Է����ּ���. \n";
		}

	}

	//�� ���� ���ڸ� �̾� �ٿ� ���
	string append_sentence;

	append_sentence = sentence1.append(sentence2);
	cout << "�� ���� ���ڸ� �̾� ���̱� : " << append_sentence << "\n";

	//�� ���� �� ���
	int sum = 0;

	// �̾� ���� �κ� ����
	int find_sentence2 = sentence1.find(sentence2);
	sentence1.resize(find_sentence2);

	sum = stoi(sentence1) + stoi(sentence2);
	cout << "�� ������ �� : " << sum;


	return 0;
}


int check_num(string str) {
	//���ڸ� ���, ���ڸ� 0
	int is_num= 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]) == 0) {
			//str�� ������
			is_num += 0;
		}
		else {
			//str�� ������
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
