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

    ifstream read_file("hello.txt");

    if (read_file.is_open())
    {
        string line;
        for (int i = 0; i < 3; i++)
        {
            getline(read_file, line);
            v.push_back(line);
        }
    }
    read_file.close();

    ofstream write_file("output.txt");
    if (write_file.is_open()) {
        for (int i = 0; i < 3; i++)
        {
            write_file << v[v.size()-1] << "\n";
            v.pop_back();
        }
    }

    write_file.close();
    

    return 0;
}
