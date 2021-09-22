//63.จงเขียนโปรแกรม Copy ไฟล์ข้อมูลโดยให้นักศึกษาป้อนข้อมูลของไฟล์ต้นทาง
//และข้อมูลไฟล์ปลายทาง (Level 4)

/* 
Input : c:\temp\data1.txt
Output : d:\temp\data2.txt 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string fname1;
    cout << "Enter source file directories (like C:\\temp\\data1.txt) : ";
    getline(cin, fname1);

    ifstream Read_file(fname1.c_str());
    if (!Read_file.is_open())
    {
        cout << "Error in opening source file!!";
        exit(1);
    }

    string fname2;
    cout << "Enter target file directories (like D:\\temp\\data2.txt ) : ";
    getline(cin, fname2);

    ofstream Write_file(fname2.c_str());
    if (!Write_file.is_open())
    {
        cout << "Error in opening target file!!";
        exit(2);
    }

    vector<string> copied;
    string input;

    while (Read_file.good())
    {
        getline(Read_file, input);
        copied.push_back(input);
    }

    for (auto paste : copied)
    {
        Write_file << paste << endl;
    }
    cout << "\nFile successfully copied !!\n\n";
    Read_file.close();
    Write_file.close();

    return 0;
}