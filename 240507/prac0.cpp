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

    //hello 파일 열기
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
            //라인 받아오기
            string line;
            getline(read_file, line);
            v.push_back(line);
        }*/
    }
    //hello 파일 닫기
    read_file.close();

    //output 파일 열기
    ofstream write_file("output.txt");

    //output 파일에 문장 적기
    if (write_file.is_open()) {
        for (int i = 0; i < 3; i++)
        {
            write_file << v.back() << "\n";
            v.pop_back(); //마지막 요소 제거
        }
    }

    //output 파일 닫기
    write_file.close();
    

    return 0;
}
