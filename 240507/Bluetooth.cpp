
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;


int main() {
	vector<string> v;

	//Bluetooth_info 파일 열기
	ifstream read_file("Bluetooth_info.txt");
	if (read_file.is_open() == false)
	{
		return -1;
	}
	string line;
	int lineCnt = 0;
	//EOF
	while (getline(read_file, line))
	{
		lineCnt++;
		v.push_back(line);
	}
	read_file.close();

	cout << v[0] << "\n";
	string* RSSI_size = new string[lineCnt];
	int line_size = 0;
	for (int i = 0; i < lineCnt; i++)
	{
		line_size = v[i].length();
		RSSI_size[i] = v[i][line_size-2] + v[i][line_size-1];
		cout << RSSI_size << "\n";
	}

	return 0;
}