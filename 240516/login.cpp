#include "User.h"

void User::showUserInfo()
{


}

string User::getID()
{
	return "0";
}

string User::getPassword()
{
	return "0";
}

string User::getNickname()
{
	return "0";
}

int User::getGamePoint()
{
	return 0;
}

void User::setID()
{

}

void User::setPassword()
{

}

void User::setNickname()
{

}

void User::setGamePoint()
{

}

void UserDataManager::writeUser(vector<string> userInfo)
//ȸ������ ����
//userInfo = {ID, password, nickname, point}
{
	vector<vector<string>> data = openUser();

	int userNum = data.size();
	int option = 1; // 1: ȸ������ 2: ����ȸ��
	string targetID; // �����ϴ� user�� ID

	//���� ȸ������ �ƴ��� Ȯ��
	//���̵� �񱳸� ���� Ȯ��
	//���� ȸ���̶�� ȸ���� ID ���� & ����� ȸ�� ����(point)�� ����
	for (int i = 0; i < userNum; i++)
	{
		if (data[i][0] == userInfo[0])
		{
			option = 2;
			targetID = data[i][0];
			data[i][3] = userInfo[3];
		}
	}

	//ȸ�������� ��� data�� ���ο� ȸ�� �߰�
	if (option == 1)
	{
		data.push_back(userInfo);
		userNum++;
	}

	//���� ���� ����

	ofstream file("User.txt");

	//���Ͽ� ȸ�� ���� ����
	for (int i = 0; i < userNum; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			file << data[i][j] << " ";
		}
		file << "\n";
	}

	file.close();
}

vector<vector<string>> UserDataManager::openUser()
{
	//������ ���ȴ��� Ȯ��
	ifstream file("User.txt");
	if (!file.is_open()) {

	}

	//ȸ���� ������ ������ ����
	vector<vector<string>> data;
	string line;

	//���� �о����
	while (getline(file, line)) {
		istringstream iss(line);
		string word;
		vector<std::string> row;

		// �ٿ��� �ܾ �и��Ͽ� ���Ϳ� ����
		while (iss >> word) {
			row.push_back(word);
		}

		// �� ���� �����͸� ���� ���Ϳ� �߰�
		data.push_back(row);
	}

	file.close();

	return data;
}

void UserDataManager::signUp() //ȸ������
{
	vector<string> user;
	string ID, password, checkingpassword, nickname;

	cout << "---------------------ȸ������---------------------\n";

	while (true)
	{
		cout << "���̵�			: ";
		cin >> ID;
		cout << "��й�ȣ			: ";
		cin >> password;
		cout << "��й�ȣ Ȯ��	: ";
		cin >> checkingpassword;
		cout << "�г���			: ";
		cin >> nickname;

		if (password != checkingpassword)
		{
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n";
		}
		else {
			break;
		}
	}

	user.push_back(ID);
	user.push_back(password);
	user.push_back(nickname);
	user.push_back("1000000"); // ȸ�����Խ� �⺻ ���� ����Ʈ
	writeUser(user);

	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�. \n";
	//read_file.close();
}

vector<string> UserDataManager::login() //�α��� return : Nickname, point
{
	vector<vector<string>> data = openUser();
	bool isUser = false;
	int userNum = data.size();
	int userIndex = -1; // �α����ϴ� user�� index
	vector<string> user; //�α��� �� ������ ����
	string ID, password;

	//ID�� �����ϴ� �� Ȯ��
	while (isUser == false)
	{
		cout << "���̵�			: \n";
		cin >> ID;
		// data�� ���Ǹ� id�� �����ϴ��� Ȯ��
		for (int i = 0; i < userNum; i++)
		{
			if (ID == data[i][0])
			{
				isUser = true;
				userIndex = i;
			}
		}

		if (isUser == false)
		{
			cout << "�������� �ʴ� ���̵��Դϴ�. \n";
			cout << "�ٽ� �Է����ּ���. \n";
		}
	}

	while (true)
	{
		cout << "��й�ȣ			: \n";
		cin >> password;

		if (password == data[userIndex][1])
		{
			cout << "�α��ο� �����߽��ϴ�. \n";
			break;
		}
		else
		{
			cout << "�ٽ� �Է����ּ��� : \n";
		}
	}

	// user�� Nickname, Point ���� ����
	user.push_back(data[userIndex][2]);
	user.push_back(data[userIndex][3]);

	return user;
}

