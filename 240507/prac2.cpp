//240507
//prac2 회원 명부를 응용한 로그인 기능

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool CompareString(string my_info, string user_info);
bool FindMem(string name);
void AddTel(string name);
void EditTel(string name);

/*
장서영 000000 
홍길동 111111 
김철수 098765 
*/

int main() {
	string name;
	string password;
	int memRow = 0; // 회원수 = 배열의 ROW
	int memCol = 2;

	//파일 읽어오기
	ifstream read_file("member.txt");

	if (read_file.is_open() == false)
	{
		cout << "파일이 열리지 않았습니다.";
		return 0;
	}

	string line1;
	int loop_cnt = 0;

	// 회원 수 파악
	while (getline(read_file, line1))
	{
		memRow++;
	}

	// 배열 선언
	string** member = new string * [memRow];

	for (int i = 0; i < memRow; i++)
	{
		member[i] = new string[memCol];
	}
	read_file.clear();
	read_file.seekg(0, ios::beg);

	//한 줄 씩 받아오기
	while (getline(read_file, line1))
	{
		istringstream line2(line1);
			
		// 이름과 비밀번호 분리
		for (int i = 0; i < 2; i++)
		{
			line2 >> member[loop_cnt][i];
		}
		loop_cnt++;
	}

	read_file.close();
	/*
	int option = 0;
	cout << "원하시는 기능을 고르세요. \n";
	cout << "1. 로그인하기 2. 회원가입하기 3. 프로그램 종료 \n";
	cin >> option;
	*/
	
	int same_name = 0;
	int index = -1;

	cout << "이름을 입력하세요 : ";

	while (same_name == 0)
	{
		cin >> name;
		
		for (int i = 0; i < 3; i++)
		{
			if (CompareString(member[i][0], name)) {
				same_name = 1;
				index = i;
				break;
			}
		}

		if (same_name == 0)
		{
			cout << "다시 입력해주세요 : ";
		}
	}

	cout << "비밀번호를 입력하세요 : ";
	while (true)
	{
		cin >> password;

		if (CompareString(member[index][1], password))
		{
			cout << "로그인에 성공했습니다. \n\n";
			break;
		}
		else
		{
			cout << "다시 입력해주세요 : ";
		}
	}

	//member_tel에 사용자 있는 지 확인
	if (FindMem(member[index][0]) == true) {
		//전화번호 수정
		EditTel(member[index][0]);
	}
	else {
		//전화번호 추가
		AddTel(member[index][0]);
	}

	//동적 배열 해제
	for (int i = 0; i < memCol; i++)
	{
		delete[] member[i];
	}

	return 0;
}

// 문자열 비교하는 함수
bool CompareString(string my_info, string user_info)
{
	//my_info : 내가 가지고 있는 정보, user_info : 사용자가 전해준 정보
	if (my_info.compare(user_info) == 0)
	{
		return true;
	}

	return false;
}

// member_tel에 이름이 존재하는지 확인
bool FindMem(string name)
{
	ifstream read_file("member_tel.txt");
	string line;
	int loop_cnt = 0;

	while (getline(read_file, line))
	{
		if (line.find(name) == 0)
		{
			read_file.close();
			return true;
		}
	}

	read_file.close();

	return false;
}

// 이름, 전화번호 추가
void AddTel(string name)
{
	string tel;
	cout << "전화번호를 입력하세요. \nex) 010-1111-2222\n";
	cin >> tel;

	ofstream write_file("member_tel.txt",ios_base::app);

	if (write_file.is_open() == false)
	{
		cout << "파일이 열리지 않았습니다.";
	}

	write_file << "\n" << name << " " << tel;

	write_file.close();
}

// 전화번호 수정
void EditTel(string name) {
	string file_name, file_tel;
	string tel;
	int memRow = 0; // 회원수 = 배열의 ROW
	int memCol = 2; // 이름, 전화번호

	//파일 읽어오기
	ifstream read_file("member_tel.txt");
	string line;
	int loop_cnt = 0;

	// 회원 수 파악
	while (getline(read_file, line))
	{
		memRow++;
	}

	// 배열 선언
	string* member = new string [memRow];

	read_file.clear();
	read_file.seekg(0, ios::beg);

	//한 줄 씩 받아오기
	while (getline(read_file, line))
	{
		if (line.find(name) == 0)
		{
			cout << "수정할 전화번호를 입력하세요. \nex) 010-1111-2222\n";
			cin >> tel;
			member[loop_cnt] = name + ' ' + tel;
		}
		else
		{
			member[loop_cnt] = line;
		}
		loop_cnt++;
	}
	read_file.close();

	ofstream write_file("member_tel.txt");

	for (int i = 0; i < memRow; i++)
	{
		write_file << member[i] << "\n";
	}

	write_file.close();




	//동적 배열 해제
	delete[] member;


}
