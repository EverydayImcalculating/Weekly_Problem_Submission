//  63.จงเขียนโปรแกรม Copy ไฟล์ข้อมูลโดยให้นักศึกษาป้อนข้อมูลของไฟล์ต้นทาง
//  และข้อมูลไฟล์ปลายทาง (Level 4)

/* 
    Input : c:\temp\data1.txt
    Output : d:\temp\data2.txt 
*/
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int main()
{
    wstring Input;
    cout << "ENTER SOURCE FILE DIRECTORIES (LIKE C:\\temp\\data1.txt) : ";
    getline(wcin, Input);
    wstring Output;
    cout << "ENTER TARGET FILE DIRESTORIES (LIKE D:\\temp\\data2.txt) : ";
    getline(wcin, Output);

    LPCWSTR lpInput = Input.c_str();
    LPCWSTR lpOutput = Output.c_str();

    CopyFileW(lpInput, lpOutput, TRUE);

    if (GetLastError())
    {
        cout << "ERROR : CANNOT ACCESS SOURCE FILE OR SOURCE FILE NOT EXISTING..." << endl;
    }
    else
        cout << "\nSUCCESSFULLY COPIED...\n\n";

    return 0;
}
