// 240507
// 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool CheckNum(int order);

int main()
{
	vector<string> v;

    //파일 읽어오기
	ifstream read_file("plus_read_file.txt");

    int lineCnt = 0;
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

    //사용자 입력 받아오기
    cout << "원하는 줄의 순서를 입력하세요 : ";
    int* line_order = new int[lineCnt];
    int n = 0;

    while (true)
    {
        cin >> line_order[n];
        if (line_order[n] < lineCnt && CheckNum(line_order[n]))
            n++;
        else
            cout << "다시 입력해주세요 : ";

        if (n == lineCnt) {
            break;
        }
    }

    for (int i = 0; i < lineCnt; i++)
    {
        cout << line_order[i] << "\n";
    }

    /*
    //파일 write
    ofstream write_file("plus_write_file.txt");

    if (write_file.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            switch (line_order[i])
            {
                case 1 :
                    write_file << v[0] << "\n";
                    break;
                case 2 :
                    write_file << v[1] << "\n";
                    break;
                case 3 :
                    write_file << v[2] << "\n";
                    break;
                default:
                    break;
            }
        }
    }

    write_file.close();
    */

    delete[] line_order;

	return 0;
}

bool CheckNum(int order)
{
    //order이 true면 true 반환
    //false면 false 반환
    if (isdigit('o') != 0)
    {
        cout << "true";
        return true;
    }
    else
    {   
        cout << "false";
        return false;
    }
}
