//240507
//prac1 회원 명부 작성하기

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int CountWord(string info);
bool CheckInputLength(string info);

int main() {
	string member[3][2];
	string line;
	cout << "이름 비밀번호(6~18자리)를 순서대로 입력해주세요 \n";

	int n = 0;

	while(true)
	{
		int blank_cnt = 0;

		cout << n+1 << "번 회원 : ";
		getline(cin, line);

		if (CountWord(line) == 2 && CheckInputLength(line) == true)
		{
			int blank_index = line.find(' ');
			member[n][0] = line.substr(0, blank_index);
			member[n][1] = line.substr(blank_index+1);
			n++;
		}
		else 
		{
			cout << "다시 입력해주세요 : ";
		}

		if (n == 3)
		{
			break;
		}
	}

	ofstream write_file("member.txt");

	//output 파일에 문장 적기
	if (write_file.is_open()) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				write_file << member[i][j] << "\t";
			}
			write_file << "\n";
		}
	}

	//output 파일 닫기
	write_file.close();

	//파일 읽어오기
	ifstream read_file("member.txt");

	int lineCnt = 0;
	vector<string> v;

	if (read_file.is_open())
	{
		string line;
		//EOF
		while (getline(read_file, line))
		{
			lineCnt++;
			v.push_back(line);
		}
	}

	read_file.close();

	for (int i = 0; i < lineCnt; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}

int CountWord(string info)
{
	int word_cnt = 1;
	for (int i = 0; i < info.length(); i++)
	{
		if (info[i] == ' ')
		{
			word_cnt++;
		}
	}
	return word_cnt;
}

bool CheckInputLength(string info)
{
	//길이가 6~18자리이면 true 아니면 false
	if (info.length() >= 6 && info.length() <= 18)
	{
		return true;
	}

	return false;
}
