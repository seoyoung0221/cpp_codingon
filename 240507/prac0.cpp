// 240507
// 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;

    //hello ���� ����
    ifstream read_file("hello.txt");

    if (read_file.is_open())
    {
        string line;
        int lineCnt = 0;
        //EOF
        while (getline(read_file, line))
        {
            lineCnt++;
            v.push_back(line);
        }

        /*
        for (int i = 0; i < 3; i++)
        {
            //���� �޾ƿ���
            string line;
            getline(read_file, line);
            v.push_back(line);
        }*/
    }
    //hello ���� �ݱ�
    read_file.close();

    //output ���� ����
    ofstream write_file("output.txt");

    //output ���Ͽ� ���� ����
    if (write_file.is_open()) {
        for (int i = 0; i < 3; i++)
        {
            write_file << v.back() << "\n";
            v.pop_back(); //������ ��� ����
        }
    }

    //output ���� �ݱ�
    write_file.close();
    

    return 0;
}
