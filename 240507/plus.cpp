// 240507
// 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool CheckNum(string order);

int main()
{
	vector<string> v;

    //���� �о����
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

    //����� �Է� �޾ƿ���
    cout << "���ϴ� ���� ������ �Է��ϼ���. \n";
    string* line_order = new string[lineCnt];
    int n = 0;
    while (true)
    {
        cout << n + 1 << "��° �� : ";
        cin >> line_order[n];

        if (stoi(line_order[n]) < (lineCnt + 1) && CheckNum(line_order[n]))
        {
            n++;
        }
        else
            cout << "�ٽ� �Է����ּ��� : ";

        if (n == lineCnt) {
            break;
        }
    }

    //���� write
    ofstream write_file("plus_write_file.txt");

    if (write_file.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            switch (stoi(line_order[i]))
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

    delete[] line_order;

	return 0;
}

bool CheckNum(string order)
{
    //order�� true�� true ��ȯ
    //false�� false ��ȯ

    for (int i = 0; i < order.length(); i++)
    {
        if (isdigit(order[i]) == 0)
        {
            cout << "false";
            return false;
        }
    }
    return true;
}
