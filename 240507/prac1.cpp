//240507
//prac1 회원 명부 작성하기


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string member[3][2];

	cout << "이름 비밀번호를 순서대로 입력해주세요 \n";

	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "번 회원 : ";
		for (int j = 0; j < 2; j++)
		{
			cin >> member[i][j];
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