// 240507
// 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v(3);

    ifstream read_file("hello.txt");

    if (read_file.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            getline(read_file, v[i]);
        }
    }
    read_file.close();

    ofstream write_file("output.txt");
    for (int i = 0; i < 3; i++)
    {
        write_file << v[3 - i - 1] << "\n";
    }
    

    return 0;
}
